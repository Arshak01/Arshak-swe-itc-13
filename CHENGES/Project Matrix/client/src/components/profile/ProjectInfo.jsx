import React, { useEffect, useState } from 'react';
import PropTypes from 'prop-types';
import { Col, Select } from 'antd';
import { useIntl } from 'react-intl';
import projectApi from '../../api/projects';
import confidentialTypesApi from '../../api/confidentialTypes';
import {
  ColWithBorder,
  ConfidentialTypeSelect,
  GreenSwitch,
  ProjectInfoStyled,
  RowWithBorder,
} from './Styled';
import arrowIcon from '../../asserts/arrow.svg';
import locale from './locale';

const { Option } = Select;

const ProjectInfo = ({
  projectData: {
    id,
    confidentialType,
    isBillable,
    isActive,
    achievementsReport,
  },
  setProject,
}) => {
  const { formatMessage } = useIntl();
  const [confidentialTypes, setConfidentialTypes] = useState([]);

  useEffect(() => {
    confidentialTypesApi
      .listAll()
      .then((response) => setConfidentialTypes(response));
  }, []);

  const getConfidentialTypeColor = (id, confidentialTypes) => {
    const type = confidentialTypes.find((type) => type.id === id).name; // TODO
    switch (type) {
      case 'Strictly Private':
        return '#F2453D';
      case 'On Request':
        return '#FFCA28';
      case 'Standard':
        return '#4CAF50';
    }
  };

  const updateProject = (projectField, serverField) => (value) => {
    projectApi.update(id, { project: { [serverField]: value } });
    setProject((project) => ({ ...project, [projectField]: value })); // TODO: move to actions
  };

  return (
    <ProjectInfoStyled withBorder title={formatMessage(locale.projectInfo)}>
      <RowWithBorder gutter={[2, 16]}>
        <Col span={16}>{formatMessage(locale.confidentialType)}</Col>
        <ColWithBorder span={8}>
          {!!confidentialTypes.length && !!confidentialType && (
            <ConfidentialTypeSelect
              suffixIcon={<img src={arrowIcon} />}
              bordered={false}
              defaultValue={confidentialType}
              onChange={updateProject('confidentialType', 'confidential_type')}
              color={getConfidentialTypeColor(
                confidentialType,
                confidentialTypes,
              )}
            >
              {confidentialTypes.map(({ id, name }) => (
                <Option key={id} value={id}>
                  {name}
                </Option>
              ))}
            </ConfidentialTypeSelect>
          )}
        </ColWithBorder>
      </RowWithBorder>
      <RowWithBorder gutter={[2, 24]}>
        <Col span={16}>{formatMessage(locale.presales)}</Col>
        <ColWithBorder span={8}>
          {isBillable
            ? formatMessage(locale.switchValuebillable)
            : formatMessage(locale.switchValuePresales)}
          <GreenSwitch
            defaultChecked={isBillable}
            onChange={updateProject('isBillable', 'is_billable')}
            size={'small'}
          />
        </ColWithBorder>
      </RowWithBorder>
      <RowWithBorder gutter={[2, 16]}>
        <Col span={16}>{formatMessage(locale.status)}</Col>
        <ColWithBorder span={8}>
          {isActive
            ? formatMessage(locale.openStatus)
            : formatMessage(locale.closeStatus)}
          <GreenSwitch
            defaultChecked={isActive}
            onChange={updateProject('isActive', 'is_active')}
            size={'small'}
          />
        </ColWithBorder>
      </RowWithBorder>
      <RowWithBorder gutter={[2, 16]}>
        <Col span={16}>{formatMessage(locale.achievementsReports)}</Col>
        <ColWithBorder span={8}>
          {achievementsReport
            ? formatMessage(locale.achievementsReportsYes)
            : formatMessage(locale.achievementsReportsNo)}
          <GreenSwitch
            defaultChecked={achievementsReport}
            onChange={updateProject(
              'achievementsReport',
              'achievements_report',
            )}
            size={'small'}
          />
        </ColWithBorder>
      </RowWithBorder>
    </ProjectInfoStyled>
  );
};

ProjectInfo.propTypes = {
  projectData: PropTypes.exact({
    id: PropTypes.number,
    isActive: PropTypes.boolean,
    achievementsReport: PropTypes.boolean,
    isBillable: PropTypes.boolean,
    confidentialType: PropTypes.string,
  }),
  setProject: PropTypes.func,
};

export default ProjectInfo;
