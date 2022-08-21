import React, { useCallback, useEffect, useState } from 'react';
import { Link, useNavigate } from 'react-router-dom';
import { useIntl } from 'react-intl';
import { useDispatch, useSelector } from 'react-redux';
import { useFormik } from 'formik';
import { Col, Row } from 'antd';

import { createProject } from '../../actions/active-projects-actions';
import { metaSelector } from '../../selectors/meta';
import {
  accountLeadsSelector,
  projectManagersSelector,
  teamLeadsSelector,
} from '../../selectors/employees';
import { isCreatingSelector } from '../../selectors/projects';
import { PROJECT_PAGE, PROJECT_PROFILE_PAGE } from '../../utils/constants';
import { GroupsSpinnerContainer } from '../spinner/SpinnerStyled';
import Spinner from '../spinner/Spinner';
import FloatInputHOC from '../FloatInputHOC';
import {
  AutoCompleteField as AutoComplete,
  CalendarDatePicker,
  InputField as Input,
  ProjectLayout,
  CustomerSectionButtonDiv as ProjectSectionButtonDiv,
  ProjectSectionCard,
  ProjectSectionLayout,
  SectionButtonDiscard,
  SectionButtonSave,
  SelectField as Select,
} from '../../Styled';
import locale from './locale';
import { createProjectValidationSchema } from './CreateProject.schema';

const FloatingInput = FloatInputHOC(Input);
const FloatingCalendar = FloatInputHOC(CalendarDatePicker);
const FloatingSelect = FloatInputHOC(Select);
const FloatingAutoComplete = FloatInputHOC(AutoComplete);

const initialValues = {
  name: '',
  startDate: null,
  endDate: null,
  customer: null,
  country: '',
  engagementModel: '',
  engagementCategory: '',
  accountLead: '',
  agent: '',
  teamLead: '',
  projectManager: '',
};

const createOptionsForEmployee = (arr) =>
  arr.map(({ id, name, surname }) => ({
    value: id,
    label: `${name} ${surname}`,
  }));

const createOptionsForMeta = (arr) =>
  arr.map(({ id, name }) => ({
    label: name,
    value: id,
  }));

export const CreateProjectForm = () => {
  const [agent, setAgent] = useState([]);
  const [accountLeads, setAccountLeads] = useState([]);
  const [countries, setCounties] = useState([]);
  const [engagementCategories, setEngagementCategories] = useState([]);
  const [engagementModeles, setEngagementModeles] = useState([]);
  const [projectManagers, setProjectManagers] = useState([]);
  const [teamLeads, setTeamLeads] = useState([]);

  const { formatMessage } = useIntl();
  const navigate = useNavigate();
  const dispatch = useDispatch();

  const metaData = useSelector(metaSelector);
  const accountLeadsData = useSelector(accountLeadsSelector);
  const projectManagersData = useSelector(projectManagersSelector);
  const teamLeadsData = useSelector(teamLeadsSelector);
  const isCreatingFinished = useSelector(isCreatingSelector);

  const onDiscard = () => {
    navigate(PROJECT_PAGE);
  };

  useEffect(() => {
    setAgent(createOptionsForMeta(metaData.agents));
    setCounties(createOptionsForMeta(metaData.countries));
    setEngagementModeles(createOptionsForMeta(metaData.engagementModels));
    setEngagementCategories(
      createOptionsForMeta(metaData.engagementCategories),
    );
  }, [metaData]);

  useEffect(() => {
    setAccountLeads(createOptionsForEmployee(accountLeadsData));
  }, [accountLeadsData]);

  useEffect(() => {
    setTeamLeads(createOptionsForEmployee(teamLeadsData));
  }, [teamLeadsData]);

  useEffect(() => {
    setProjectManagers(createOptionsForEmployee(projectManagersData));
  }, [projectManagersData]);

  const {
    dirty,
    handleSubmit,
    // handleBlur,
    isSubmitting,
    handleChange,
    setFieldValue,
    errors: formikErrors,
    values,
    isValid,
    // touched,
  } = useFormik({
    initialValues,
    validationSchema: createProjectValidationSchema(formatMessage),
    onSubmit: (values) => {
      //TODO
      dispatch(createProject(values)).then((res) => {
        const to = PROJECT_PROFILE_PAGE.replace(
          ':projectName',
          res.payload.name.toLowerCase(),
        );
        navigate(to);
      });
    },
  });

  const handleSelect = (id, fieldKey) => setFieldValue(fieldKey, id);

  const handleInputChange = useCallback(
    (e) => {
      if (values.name !== e.target.name) {
        handleChange(e);
      }
    },
    [values.name, handleChange],
  );

  const handleDateChange = useCallback(
    (date, fieldName) => {
      setFieldValue(fieldName, date);
      if (fieldName.includes('startDate')) {
        if (values.endDate?.isBefore(date)) {
          setFieldValue('endDate', null);
        }
      }
    },
    [values.endDate, setFieldValue],
  );

  const handleCustomerChange = useCallback(
    (customer, fieldName) => {
      setFieldValue(fieldName, customer);
    },
    [setFieldValue],
  );

  const getErrorMessage = (fieldName) => {
    const errorMessage = formikErrors[fieldName];
    if (errorMessage?.includes('required')) return '';
    if (fieldName === 'name' && errorMessage?.includes('view click -')) {
      const toUrl = PROJECT_PROFILE_PAGE.replace(
        ':projectName',
        values.name.toLowerCase(),
      );
      return (
        <>
          {errorMessage}
          <Link to={toUrl}>here</Link>
        </>
      );
    }
    if (
      errorMessage?.includes(
        'startDate must be a `string` type, but the final value was: `null`.',
      ) &&
      fieldName === 'startDate'
    )
      return '';
    return errorMessage;
  };
  const isButtonDisabled = !dirty || !isValid;

  return (
    <ProjectLayout>
      <ProjectSectionLayout>
        <ProjectSectionCard
          title={formatMessage(locale.placeholderProjectCreation)}
        >
          {!isCreatingFinished && isSubmitting ? (
            <GroupsSpinnerContainer>
              <Spinner large={true} />
            </GroupsSpinnerContainer>
          ) : (
            <form onSubmit={handleSubmit}>
              <Row gutter={[24, 24]}>
                <Col span={12}>
                  <FloatingInput
                    name="name"
                    tabIndex={1}
                    value={values.name}
                    placeholder={formatMessage(locale.placeholderProjectName)}
                    autoComplete="off"
                    onChange={handleInputChange}
                    errorMessage={getErrorMessage('name')}
                    required
                  />
                </Col>
                <Col span={12}>
                  <FloatingAutoComplete
                    name="customer"
                    tabIndex={2}
                    value={values.customer}
                    placeholder={formatMessage(locale.placeholderCustomer)}
                    autoComplete="off"
                    onChange={handleCustomerChange}
                    errorMessage={getErrorMessage('customer')}
                    required
                  />
                </Col>
              </Row>
              <Row gutter={[24, 24]}>
                <Col span={6}>
                  <FloatingCalendar
                    placeholder={formatMessage(locale.placeholderStartDate)}
                    type="date"
                    name="startDate"
                    tabIndex={3}
                    onChange={(date) => handleDateChange(date, 'startDate')}
                    value={values.startDate}
                    disabledDate={(date) =>
                      !date || date.isSameOrBefore('2005-01-01')
                    }
                    errorMessage={getErrorMessage('startDate')}
                    required
                  />
                </Col>
                <Col span={6}>
                  <FloatingCalendar
                    placeholder={formatMessage(locale.placeholderEndDate)}
                    type="date"
                    name="endDate"
                    tabIndex={4}
                    onChange={(date) => handleDateChange(date, 'endDate')}
                    value={values.endDate}
                    disabledDate={(date) => date.isBefore(values.startDate)}
                  />
                </Col>

                <Col span={12}>
                  <FloatingSelect
                    name="country"
                    tabIndex={5}
                    options={countries}
                    value={values.country}
                    placeholder={formatMessage(locale.placeholderCountry)}
                    autoComplete="off"
                    onChange={(id) => handleSelect(id, 'country')}
                    allowClear
                  />
                </Col>
              </Row>
              <Row gutter={[24, 24]}>
                <Col span={12}>
                  <FloatingSelect
                    name="engagementModel"
                    tabIndex={6}
                    options={engagementModeles}
                    value={values.engagementModel}
                    placeholder={formatMessage(
                      locale.placeholderEngagementModel,
                    )}
                    autoComplete="off"
                    onChange={(id) => handleSelect(id, 'engagementModel')}
                    errorMessage={getErrorMessage('engagementModel')}
                    required
                  />
                </Col>
                <Col span={12}>
                  <FloatingSelect
                    name="engagementCategory"
                    tabIndex={7}
                    options={engagementCategories}
                    value={values.engagementCategory}
                    placeholder={formatMessage(
                      locale.placeholderEngagementCategory,
                    )}
                    autoComplete="off"
                    onChange={(id) => handleSelect(id, 'engagementCategory')}
                    errorMessage={getErrorMessage('engagementCategory')}
                    required
                  />
                </Col>
              </Row>
              <Row gutter={[24, 24]}>
                <Col span={12}>
                  <FloatingSelect
                    name="accountLead"
                    tabIndex={8}
                    options={accountLeads}
                    value={values.accountLead}
                    placeholder={formatMessage(locale.placeholdeAccountLead)}
                    autoComplete="off"
                    onChange={(id) => handleSelect(id, 'accountLead')}
                    errorMessage={getErrorMessage('accountLead')}
                    required
                  />
                </Col>
                <Col span={12}>
                  <FloatingSelect
                    name="agent"
                    tabIndex={9}
                    options={agent}
                    value={values.agent}
                    placeholder={formatMessage(locale.placeholdeAgent)}
                    autoComplete="off"
                    onChange={(id) => handleSelect(id, 'agent')}
                    allowClear
                  />
                </Col>
              </Row>
              <Row gutter={[24, 24]}>
                <Col span={12}>
                  <FloatingSelect
                    name="teamLead"
                    tabIndex={10}
                    options={teamLeads}
                    value={values.teamLead}
                    placeholder={formatMessage(locale.placeholdeTeamLead)}
                    autoComplete="off"
                    onChange={(id) => handleSelect(id, 'teamLead')}
                    allowClear
                  />
                </Col>
                <Col span={12}>
                  <FloatingSelect
                    name="projectManager"
                    tabIndex={11}
                    options={projectManagers}
                    value={values.projectManager}
                    placeholder={formatMessage(
                      locale.placeholderProjectManager,
                    )}
                    autoComplete="off"
                    onChange={(id) => handleSelect(id, 'projectManager')}
                    allowClear
                  />
                </Col>
              </Row>
              <ProjectSectionButtonDiv>
                <SectionButtonDiscard
                  type="link"
                  tabIndex={12}
                  fullwidth="true"
                  onClick={onDiscard}
                >
                  <strong>{formatMessage(locale.discardCta)}</strong>
                </SectionButtonDiscard>
                <SectionButtonSave
                  type="link"
                  tabIndex={13}
                  fullwidth="true"
                  disabled={isButtonDisabled}
                  htmlType="submit"
                >
                  <strong>{formatMessage(locale.createCta)}</strong>
                </SectionButtonSave>
              </ProjectSectionButtonDiv>
            </form>
          )}
        </ProjectSectionCard>
      </ProjectSectionLayout>
    </ProjectLayout>
  );
};
