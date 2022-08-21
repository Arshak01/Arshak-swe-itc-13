import { Col, Row, Upload, message } from 'antd';
import { ConfigProvider } from 'antd-country-phone-input';
import { useFormik } from 'formik';
import moment from 'moment';
import React, { useCallback, useEffect, useState } from 'react';
import { useIntl } from 'react-intl';
import { useDispatch, useSelector } from 'react-redux';
import { useNavigate, useParams } from 'react-router-dom';
import en from 'world_countries_lists/data/countries/en/world.json';
import PageHeader from '../PageHeader';
import {
  getSingleProject,
  updateProject,
} from '../../actions/active-projects-actions';
import {
  getAccountLeads,
  getProjectManagers,
  getTeamLeads,
} from '../../actions/employees-actions';
import {
  accountLeadsSelector,
  projectManagersSelector,
  teamLeadsSelector,
} from '../../selectors/employees';
import { metaSelector } from '../../selectors/meta';
import {
  isCreatingSelector,
  projectFormDataSelector,
} from '../../selectors/projects';
import {
  PageContainerEdit as Container,
  ProjectSectionLayout,
  SectionButtonDiscard,
  SectionButtonSave,
} from '../../Styled';
import {
  PROJECT_PROFILE_PAGE,
  RANGE_FROMAT,
  ROLES,
} from '../../utils/constants';
import FloatInputHOC from '../FloatInputHOC';
import Spinner from '../spinner/Spinner';
import { GroupsSpinnerContainer } from '../spinner/SpinnerStyled';
import { editProjectValidationSchema } from './EditProject.schema';
import {
  ActionsButtonSection,
  DropDownIcon,
  InputField,
  PhoneInput,
  SectionCard,
  SectionTitle,
  SelectField,
  StyledRangePicker,
  StyledTextArea,
  UploadIcon,
  UploadWrapper,
} from './EditProjectFormStyled';
import locale from './locale';
import { ReactComponent as CalendarIcon } from './assets/calendar.svg';
import { ReactComponent as ArrowDown } from './assets/arrowdown.svg';
import Icon, { CloseCircleFilled } from '@ant-design/icons';
import { uploadLogo } from '../../api/projects';

const FloatingInput = FloatInputHOC(InputField);
const FloatingCalendar = FloatInputHOC(StyledRangePicker);
const FloatingSelect = FloatInputHOC(SelectField);
const FloatingTextArea = FloatInputHOC(StyledTextArea);
const FloatingPhoneInput = FloatInputHOC(PhoneInput);
const FloatingDragger = FloatInputHOC(Upload.Dragger);
const ArrowDownIcon = <DropDownIcon component={ArrowDown} />;

export const EditProjectForm = () => {
  const [options, setOptions] = useState({
    engagementCategories: [],
    engagementModels: [],
    agent: [],
    country: [],
    accountLead: [],
    teamLead: [],
    projectManager: [],
    achievements_report: [
      { value: true, label: 'Yes' },
      { value: false, label: 'No' },
    ],
  });
  const [initialValues, setInitialValues] = useState({});
  const [isNameTouched, setIsNameTouched] = useState(false);

  const navigate = useNavigate();
  const params = useParams();
  const { formatMessage } = useIntl();
  const dispatch = useDispatch();
  const metaData = useSelector(metaSelector);

  const accountLeadsData = useSelector(accountLeadsSelector);
  const projectManagersData = useSelector(projectManagersSelector);
  const teamLeadsData = useSelector(teamLeadsSelector);
  const isCreatingFinished = useSelector(isCreatingSelector);
  const formData = useSelector(projectFormDataSelector);

  const setFieldOptions = (data) => {
    return data.map(({ id, name }) => ({ label: name, value: id }));
  };

  useEffect(() => {
    dispatch(getSingleProject(params.projectName));
    dispatch(getAccountLeads());
    dispatch(getTeamLeads());
    dispatch(getProjectManagers());
  }, [dispatch, params.projectName]);

  useEffect(() => {
    setOptions((prevOptions) => ({
      ...prevOptions,
      country: setFieldOptions(metaData.countries),
      engagementModels: setFieldOptions(metaData.engagementModels),
      engagementCategories: setFieldOptions(metaData.engagementCategories),
      agent: setFieldOptions(metaData.agents),
    }));
  }, [metaData]);

  useEffect(() => {
    setOptions((prevOptions) => ({
      ...prevOptions,
      accountLead: setFieldOptions(accountLeadsData),
      teamLead: setFieldOptions(teamLeadsData),
      projectManager: setFieldOptions(projectManagersData),
    }));
  }, [accountLeadsData, projectManagersData, teamLeadsData]);

  const getHrEmployeeId = (role, allocations) => {
    const allocation = allocations.find(
      (employee) =>
        employee.role.name.trim() === role &&
        (!employee.end_date || moment(employee.end_date).isAfter(moment())),
    );
    return allocation ? allocation.employee.hr_employee.id : '';
  };

  const initializeFormData = useCallback((data) => {
    setInitialValues({
      id: data.id,
      name: data.name,
      startDate: moment(data.start_date),
      endDate: data.end_date ? moment(data.end_date) : '',
      budget: data.budget,
      countryId: data.country_id,
      customerId: data.customer_id,
      engagementModel: data.model_id,
      engagementCategory: data.category_id,
      agent: data.agent_id,
      about: data.about,
      achievements_report: data.achievements_report,
      technologyTools: data.technology_tools,
      logoUrl: data.logo_url,
      projectManager: getHrEmployeeId(
        ROLES.PROJECT_MANAGER,
        data.employee_allocations,
      ),
      teamLead: getHrEmployeeId(ROLES.PROJECT_LEAD, data.employee_allocations),
      accountLead: getHrEmployeeId(
        ROLES.ACCOUNT_LEAD,
        data.employee_allocations,
      ),
      customerName: data.customer.name,
      customerPhone: data.customer.contact_phone || { short: 'US' },
      customerEmail: data.customer.email,
      customerAddress: data.customer.address,
      customerInfo: data.customer.about,
    });
  }, []);

  useEffect(() => {
    initializeFormData(formData);
  }, [formData, initializeFormData]);

  const {
    handleSubmit,
    isSubmitting,
    handleChange,
    setFieldValue,
    errors,
    values,
    touched,
    isValid,
    dirty,
  } = useFormik({
    initialValues,
    enableReinitialize: true,
    validationSchema: editProjectValidationSchema(formatMessage, isNameTouched),
    onSubmit: (values) => {
      if (isValid && dirty) {
        const {
          customerAddress,
          customerEmail,
          customerInfo,
          customerName,
          customerPhone,
          teamLead,
          projectManager,
          accountLead,
          ...project
        } = values;
        const data = {
          project,
          customer: {
            address: customerAddress,
            email: customerEmail,
            about: customerInfo,
            name: customerName,
            contact_phone: customerPhone,
          },
          teamLead,
          projectManager,
          accountLead,
        };
        dispatch(updateProject(params.projectName, data));
      }
    },
  });

  const redirectToProfilePage = useCallback(
    (projectName) => {
      navigate(
        PROJECT_PROFILE_PAGE.replace(
          ':projectName',
          projectName || values.name.toLowerCase(),
        ),
      );
    },
    [navigate, values.name],
  );

  useEffect(() => {
    if (!isCreatingFinished && isSubmitting && isValid) {
      redirectToProfilePage();
    }
  }, [
    isCreatingFinished,
    isSubmitting,
    isValid,
    navigate,
    redirectToProfilePage,
    values.name,
  ]);

  const onDiscard = () => redirectToProfilePage(params.projectName);

  const onFilter = (id, fieldKey, dataList) => {
    const item = dataList.filter(({ value }) => value === id)[0];
    setFieldValue(fieldKey, item.value);
  };

  const handleInputChange = useCallback(
    (e) => {
      handleChange(e);
      if (initialValues.name !== e.target.value) {
        setIsNameTouched(true);
      } else {
        setIsNameTouched(false);
      }
    },
    [initialValues.name, handleChange],
  );

  const handleDateChange = useCallback(
    (date) => {
      setFieldValue('startDate', date[0]);
      setFieldValue('endDate', date[1]);
    },
    [setFieldValue],
  );

  const showUploadStatus = async (info) => {
    const status = info.file.status;
    if (status === 'done') {
      message.success(`${info.file.name} file uploaded successfully.`);
    } else if (status === 'error') {
      message.error(`${info.file.name} file upload failed.`);
    }
  };

  const handleFileUpload = async ({ file, onSuccess }) => {
    const formData = new FormData();
    formData.append('File', file);
    const { logo_url } = await uploadLogo(values.id, formData);
    setFieldValue('logoUrl', logo_url);
    onSuccess('ok');
  };

  const handleOnClear = (fieldKey) => setFieldValue(fieldKey, '');

  return (
    <ProjectSectionLayout>
      <Container>
        <PageHeader title={params.projectName} />
        {!isCreatingFinished && isSubmitting ? (
          <GroupsSpinnerContainer>
            <Spinner large={true} />
          </GroupsSpinnerContainer>
        ) : (
          <ConfigProvider locale={en}>
            <form onSubmit={handleSubmit}>
              <SectionCard>
                <SectionTitle level={4}>Project Information</SectionTitle>
                <Row gutter={[24, 24]}>
                  <Col span={12}>
                    <FloatingInput
                      name="name"
                      tabIndex={1}
                      autoComplete="off"
                      value={values.name}
                      placeholder={formatMessage(locale.placeholderProjectName)}
                      errorMessage={touched.name && errors.name}
                      onChange={handleInputChange}
                      lightLabel
                      required
                    />
                  </Col>
                  <Col span={12}>
                    <UploadWrapper>
                      <FloatingDragger
                        name="file"
                        tabIndex={2}
                        multiple={false}
                        showUploadList={false}
                        onChange={showUploadStatus}
                        label={formatMessage(locale.placeholderProjectLogo)}
                        customRequest={handleFileUpload}
                        lightLabel
                      >
                        Drag your logo here
                        <UploadIcon rotate={137} />
                      </FloatingDragger>
                    </UploadWrapper>
                  </Col>
                </Row>
                <Row gutter={[24, 24]}>
                  <Col span={12}>
                    <FloatingCalendar
                      name="date"
                      tabIndex={3}
                      label={formatMessage(locale.placeholderDateRange)}
                      value={[values.startDate, values.endDate]}
                      allowEmpty={[false, true]}
                      suffixIcon={<Icon component={CalendarIcon} />}
                      errorMessage={errors.date}
                      onChange={(date) => handleDateChange(date)}
                      format={RANGE_FROMAT}
                      lightLabel
                      required
                    />
                  </Col>
                  <Col span={12}>
                    <FloatingSelect
                      name="countryId"
                      tabIndex={4}
                      autoComplete="off"
                      suffixIcon={ArrowDownIcon}
                      options={options.country}
                      placeholder={formatMessage(locale.placeholderCountry)}
                      value={values.countryId}
                      errorMessage={errors.countryId}
                      onChange={(id) =>
                        onFilter(id, 'countryId', options.country)
                      }
                      onClear={() => handleOnClear('countryId')}
                      allowClear
                      lightLabel
                    />
                  </Col>
                </Row>
                <Row gutter={[24, 24]}>
                  <Col span={12}>
                    <FloatingSelect
                      name="engagementModel"
                      tabIndex={5}
                      autoComplete="off"
                      suffixIcon={ArrowDownIcon}
                      options={options.engagementModels}
                      placeholder={formatMessage(
                        locale.placeholderEngagementModel,
                      )}
                      value={values.engagementModel}
                      errorMessage={errors.engagementModel}
                      onChange={(id) => {
                        onFilter(
                          id,
                          'engagementModel',
                          options.engagementModels,
                        );
                      }}
                      lightLabel
                      required
                    />
                  </Col>
                  <Col span={12}>
                    <FloatingSelect
                      name="engagementCategory"
                      tabIndex={6}
                      autoComplete="off"
                      suffixIcon={ArrowDownIcon}
                      options={options.engagementCategories}
                      placeholder={formatMessage(
                        locale.placeholderEngagementCategory,
                      )}
                      value={values.engagementCategory}
                      errorMessage={errors.engagementCategory}
                      onChange={(id) => {
                        onFilter(
                          id,
                          'engagementCategory',
                          options.engagementCategories,
                        );
                      }}
                      lightLabel
                      required
                    />
                  </Col>
                </Row>
                <Row gutter={[24, 24]}>
                  <Col span={12}>
                    <FloatingInput
                      name="budget"
                      tabIndex={7}
                      autoComplete="off"
                      placeholder={formatMessage(
                        locale.placeholderProjectBudget,
                      )}
                      value={values.budget}
                      errorMessage={errors.budget}
                      onChange={handleChange}
                      lightLabel
                    />
                  </Col>
                  <Col span={12}>
                    <FloatingSelect
                      name="teamLead"
                      tabIndex={8}
                      showSearch
                      autoComplete="off"
                      suffixIcon={ArrowDownIcon}
                      options={options.teamLead}
                      placeholder={formatMessage(locale.placeholderTeamLead)}
                      value={values.teamLead}
                      errorMessage={errors.teamLead}
                      filterOption={(input, option) =>
                        option.label.toLowerCase().includes(input.toLowerCase())
                      }
                      onChange={(id) => {
                        onFilter(id, 'teamLead', options.teamLead);
                      }}
                      onClear={() => handleOnClear('teamLead')}
                      allowClear
                      lightLabel
                    />
                  </Col>
                </Row>
                <Row gutter={[24, 24]}>
                  <Col span={12}>
                    <FloatingSelect
                      name="accountLead"
                      tabIndex={9}
                      showSearch
                      autoComplete="off"
                      suffixIcon={ArrowDownIcon}
                      options={options.accountLead}
                      placeholder={formatMessage(locale.placeholderAccountLead)}
                      value={values.accountLead}
                      errorMessage={errors.accountLead}
                      filterOption={(input, option) =>
                        option.label.toLowerCase().includes(input.toLowerCase())
                      }
                      onChange={(id) =>
                        onFilter(id, 'accountLead', options.accountLead)
                      }
                      clearIcon={<CloseCircleFilled />}
                      required
                      lightLabel
                    />
                  </Col>
                  <Col span={12}>
                    <FloatingSelect
                      name="achievements_report"
                      tabIndex={10}
                      autoComplete="off"
                      suffixIcon={ArrowDownIcon}
                      options={options.achievements_report}
                      placeholder={formatMessage(
                        locale.placeholderAchievementsReport,
                      )}
                      value={values.achievements_report}
                      errorMessage={errors.achievements_report}
                      onChange={(e) => setFieldValue('achievements_report', e)}
                      allowClear
                      lightLabel
                    />
                  </Col>
                </Row>
                <Row gutter={[24, 24]}>
                  <Col span={12}>
                    <FloatingSelect
                      name="agent"
                      tabIndex={11}
                      suffixIcon={ArrowDownIcon}
                      options={options.agent}
                      placeholder={formatMessage(locale.placeholderAgent)}
                      value={values.agent}
                      autoComplete="off"
                      errorMessage={errors.agent}
                      onChange={(id) => {
                        onFilter(id, 'agent', options.agent);
                      }}
                      onClear={() => handleOnClear('agent')}
                      allowClear
                      lightLabel
                    />
                  </Col>
                  <Col span={12}>
                    <FloatingSelect
                      name="projectManager"
                      tabIndex={12}
                      autoComplete="off"
                      suffixIcon={ArrowDownIcon}
                      showSearch
                      options={options.projectManager}
                      value={values.projectManager}
                      placeholder={formatMessage(
                        locale.placeholderProjectManager,
                      )}
                      errorMessage={errors.projectManager}
                      filterOption={(input, option) =>
                        option.label.toLowerCase().includes(input.toLowerCase())
                      }
                      onChange={(id) => {
                        onFilter(id, 'projectManager', options.projectManager);
                      }}
                      onClear={() => handleOnClear('projectManager')}
                      allowClear
                      lightLabel
                    />
                  </Col>
                </Row>
                <Row gutter={[24, 24]}>
                  <Col span={12}>
                    <FloatingTextArea
                      maxLength={255}
                      tabIndex={13}
                      name="about"
                      placeholder={formatMessage(
                        locale.placeholderAboutProject,
                      )}
                      showCount
                      value={values.about}
                      errorMessage={errors.about}
                      onChange={handleChange}
                      lightLabel
                    />
                  </Col>
                  <Col span={12}>
                    <FloatingTextArea
                      maxLength={255}
                      tabIndex={14}
                      name="technologyTools"
                      showCount
                      placeholder={formatMessage(
                        locale.placeholderTechnologyTools,
                      )}
                      value={values.technologyTools}
                      errorMessage={errors.technologyTools}
                      onChange={handleChange}
                      lightLabel
                    />
                  </Col>
                </Row>
              </SectionCard>
              <SectionCard>
                <SectionTitle level={4}>Customer Client</SectionTitle>
                <Row gutter={{ xs: 8, sm: 16, md: 24, lg: 32 }}>
                  <Col span={12}>
                    <FloatingInput
                      autoFocus={true}
                      tabIndex={15}
                      maxLength={50}
                      name="customerName"
                      placeholder={formatMessage(locale.customerName)}
                      value={values.customerName}
                      errorMessage={errors.customerName}
                      onChange={handleChange}
                      required
                      lightLabel
                    />
                  </Col>

                  <Col span={12}>
                    <FloatingInput
                      maxLength={50}
                      tabIndex={16}
                      name="customerAddress"
                      placeholder={formatMessage(locale.customerAddress)}
                      value={values.customerAddress}
                      errorMessage={errors.customerAddress}
                      onChange={handleChange}
                      lightLabel
                    />
                  </Col>
                </Row>
                <Row gutter={{ xs: 8, sm: 16, md: 24, lg: 32 }}>
                  <Col span={12}>
                    <FloatingInput
                      tabIndex={17}
                      maxLength={50}
                      name="customerEmail"
                      placeholder={formatMessage(locale.customerEmail)}
                      value={values.customerEmail}
                      errorMessage={errors.customerEmail}
                      onChange={handleChange}
                      lightLabel
                    />
                  </Col>

                  <Col span={12}>
                    <FloatingPhoneInput
                      maxLength={25}
                      tabIndex={18}
                      name="customerPhone"
                      type="number"
                      placeholder={formatMessage(locale.customerPhone)}
                      value={values.customerPhone}
                      errorMessage={errors.customerPhone}
                      onChange={(e) => setFieldValue('customerPhone', e)}
                      lightLabel
                    />
                  </Col>
                </Row>
                <Row gutter={{ xs: 8, sm: 16, md: 24, lg: 32 }}>
                  <Col span={24}>
                    <FloatingTextArea
                      maxLength={255}
                      tabIndex={19}
                      name="customerInfo"
                      showCount
                      placeholder={formatMessage(locale.customerInfo)}
                      value={values.customerInfo}
                      errorMessage={errors.customerInfo}
                      onChange={handleChange}
                      lightLabel
                    />
                  </Col>
                </Row>
                <ActionsButtonSection>
                  <SectionButtonDiscard
                    type="link"
                    tabIndex={20}
                    onClick={onDiscard}
                  >
                    <strong>{formatMessage(locale.discardCta)}</strong>
                  </SectionButtonDiscard>
                  <SectionButtonSave
                    type="link"
                    tabIndex={21}
                    htmlType="submit"
                  >
                    <strong>{formatMessage(locale.saveCta)}</strong>
                  </SectionButtonSave>
                </ActionsButtonSection>
              </SectionCard>
            </form>
          </ConfigProvider>
        )}
      </Container>
    </ProjectSectionLayout>
  );
};
export default EditProjectForm;
