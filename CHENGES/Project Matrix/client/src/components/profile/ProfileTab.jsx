import React, { useEffect, useState } from 'react';
import { Col, Empty, Row } from 'antd';
import { useDispatch } from 'react-redux';
import { useParams } from 'react-router-dom';
import moment from 'moment';
import { getByName } from '../../api/projects';
import EditToolButton from './EditToolButton';
import projectLogo from '../../asserts/profilePicture.svg';
import {
  About,
  ColDescription,
  ColDescriptionBudget,
  EditToolButtonPositioned,
  // ProfileCard, // TODO
  ProfileCards,
  ProfileLayout,
  ProfilePagePicture,
  ProjectInfoStyled,
  StyledText,
  TeamInfoRow,
} from './Styled';
import { useIntl } from 'react-intl';
import locale from './locale';
import CustomerInfo from './CustomerInfo';
import ProjectInfo from './ProjectInfo';
import { getAllProjects } from '../../actions/active-projects-actions';
import AllocationHistory from './AllocationHistory';
import { PROP_TYPES } from '../../utils/proptypes';

const ProfileTab = () => {
  const dispatch = useDispatch();
  const { formatMessage } = useIntl();
  const [project, setProject] = useState(null);
  const { projectName } = useParams();

  useEffect(() => {
    dispatch(getAllProjects({ pageIndex: 0, pageSize: 1, sortBy: 'id' }));
    getByName(projectName).then((project) => {
      setProject({
        id: project.id,
        logoUrl: project.logo_url,
        budget: project.budget,
        startDate: project.start_date,
        endDate: project.end_date,
        isActive: project.is_active,
        isBillable: project.is_billable,
        achievementsReport: project.achievements_report,
        confidentialType: project?.confidential_type?.id,
        about: project.about,
        technology_tools: project.technology_tools,
        employeeAllocations: project.employee_allocations,
        customer: {
          id: project.customer.id,
          name: project.customer.name,
          address: project.customer.address,
          email: project.customer.email,
          phone: project.customer.contact_phone?.phone,
        },
        accountLead: project.employee_allocations.find(
          ({ role: { name } }) => name === 'Account Lead',
        )?.employee.hr_employee,
        teamLead: project.employee_allocations.find(
          ({ role: { name } }) => name === 'Team Lead',
        )?.employee.hr_employee,
        projectManager: project.employee_allocations.find(
          ({ role }) => role.name === 'Project Manager',
        )?.employee.hr_employee,
      });
    });
  }, []);

  const formatBudget = (sum) => sum?.replace(/\d(?=(\d{3})+$)/g, '$& ');
  const getProjectDuration = () =>
    project?.endDate
      ? moment(project?.endDate).diff(project?.startDate, 'years')
      : 'None';
  return project ? (
    <ProfileLayout>
      <EditToolButtonPositioned>
        <EditToolButton />
      </EditToolButtonPositioned>
      <Row gutter={[12, 12]}>
        <Col xs={24} md={12}>
          <ProfileCards>
            <Row>
              <ProfilePagePicture src={project.log || projectLogo} />
            </Row>
            <ProjectInfoStyled title={formatMessage(locale.aboutProject)}>
              {project.about ? (
                <StyledText>{project.about}</StyledText>
              ) : (
                <Empty image={Empty.PRESENTED_IMAGE_SIMPLE} />
              )}
            </ProjectInfoStyled>
            <ProjectInfoStyled title={formatMessage(locale.technologyTools)}>
              <StyledText>{project.technology_tools}</StyledText>
            </ProjectInfoStyled>
            {/* TODO */}
            <ProjectInfoStyled>
              <TeamInfoRow gutter={[2, 5]}>
                <Col span={8}>{formatMessage(locale.teamMembers)}</Col>
                <ColDescription span={16}>
                  {/* TODO: move to BE? */}
                  {
                    project.employeeAllocations.filter(
                      ({ end_date }) => !end_date,
                    ).length
                  }
                </ColDescription>
              </TeamInfoRow>
              <TeamInfoRow>
                <Col span={8}>{formatMessage(locale.projectBudget)}</Col>
                <ColDescriptionBudget span={16}>
                  $&nbsp;{formatBudget(project.budget)}
                </ColDescriptionBudget>
              </TeamInfoRow>
              <TeamInfoRow>
                <Col span={8}>{formatMessage(locale.projectDuration)}</Col>
                {/* TODO: Figure out */}
                <ColDescription span={16}>
                  {getProjectDuration()}
                </ColDescription>
              </TeamInfoRow>
              {project.accountLead && (
                <TeamInfoRow>
                  <Col span={8}>{formatMessage(locale.accountLead)}</Col>
                  <ColDescription span={16}>
                    {project.accountLead.name}&nbsp;
                    {project.accountLead.surname}
                  </ColDescription>
                </TeamInfoRow>
              )}
              {project.teamLead && (
                <TeamInfoRow>
                  <Col span={8}>{formatMessage(locale.teamLead)}</Col>
                  <ColDescription span={16}>
                    {project.teamLead.name}&nbsp;
                    {project.teamLead.surname}
                  </ColDescription>
                </TeamInfoRow>
              )}
              {project.projectManager && (
                <TeamInfoRow>
                  <Col span={8}>{formatMessage(locale.projectManager)}</Col>
                  <ColDescription span={16}>
                    {project.projectManager.name}&nbsp;
                    {project.projectManager.surname}
                  </ColDescription>
                </TeamInfoRow>
              )}
            </ProjectInfoStyled>
          </ProfileCards>
        </Col>

        <Col xs={24} md={12}>
          <Row gutter={[2, 8]}>
            <ProjectInfo projectData={project} setProject={setProject} />
          </Row>
          <Row gutter={[2, 8]}>
            <CustomerInfo customer={project.customer} />
          </Row>

          <About gutter={[2, 8]}>
            <ProjectInfoStyled
              noMargin
              title={formatMessage(locale.customerInfo)}
            >
              {project.about ? (
                <StyledText>{project.about}</StyledText>
              ) : (
                <Empty image={Empty.PRESENTED_IMAGE_SIMPLE} />
              )}
            </ProjectInfoStyled>
          </About>
        </Col>
      </Row>
      <AllocationHistory employeeAllocations={project.employeeAllocations} />
    </ProfileLayout>
  ) : (
    'Loading'
  );
};

ProfileTab.propTypes = PROP_TYPES.PROJECT_LIST;

export default ProfileTab;
