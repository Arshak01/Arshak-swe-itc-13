import styled, { createGlobalStyle } from 'styled-components';
import { Link } from 'react-router-dom';
import { BsCheckCircleFill, BsPlus } from 'react-icons/bs';
import { MdFilterList } from 'react-icons/md';
import CountryPhoneInput from 'antd-country-phone-input';
import {
  Button,
  Card,
  DatePicker,
  Divider,
  Form,
  Input,
  Layout,
  Modal,
  PageHeader,
  Select,
  Table,
  Tabs,
  Tooltip,
} from 'antd';
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome';
import { faBell, faUserCircle } from '@fortawesome/free-solid-svg-icons';
import agent from './asserts/agent.svg';
import billable from './asserts/billable.svg';
import customer from './asserts/customer.svg';
import accountLead from './asserts/accountLead.svg';
import projectManager from './asserts/projectManager.svg';
import teamLead from './asserts/teamLead.svg';
import tableFilter from './asserts/tableFilter.svg';
import profilePicture from './asserts/profilePicture.svg';

import logo from './asserts/logo.svg';
import { NOT_FOUND_AND_UNDER_CONSTRACT } from './utils/constants';
import AutoComplete from './components/customer/AutoComplete';

const { Sider } = Layout;
const { TextArea } = Input;
const { Content } = Layout;

createGlobalStyle`
  body {
    margin: 0;
    font-family: Montserrat, Arial, sans-serif;
    -webkit-font-smoothing: antialiased;
    -moz-osx-font-smoothing: grayscale;
  }

  code {
    font-family: source-code-pro, Menlo, Monaco, Montserrat, Consolas, 'Courier New',
      monospace;
  }

  p { margin-bottom: 0;}
`;

const Logo = styled(Link).attrs({ src: logo })`
  width: 120px;
  height: 70px;
  cursor: pointer;
`;

const NotificationButton = styled.button`
  border-width: 0;
  width: 50px;
  height: 50px;
  background-color: white;
  cursor: pointer;
`;

const NotificationIcon = styled(FontAwesomeIcon).attrs({ icon: faBell })`
  color: grey;
  font-size: 25px;
`;

const Placeholder = styled(FontAwesomeIcon).attrs({ icon: faUserCircle })`
  font-size: 28px;
  color: grey;
  cursor: pointer;
`;

const Container = styled.div`
  display: flex;
  align-items: center;
  justify-content: space-between;
`;

const StyledCustomerSectionModal = styled(Modal)`
  max-width: 800px;
  .ant-modal-body {
    padding: 30px;
    gap: 15px;
  }
  .ant-modal-content {
    font-style: normal;
    font-weight: 400;
    font-size: 12px;
    line-height: 15px;
    color: #3d3d3d;
  }
  .ant-input {
    border: 1px solid rgba(61, 11, 61, 0.5);
    border-radius: 4px;
  }
  .antd-country-phone-input {
    height: 48px;
    border-radius: 4px;
    border: 1px solid rgba(61, 61, 61, 0.5);
  }
  .ant-input-textarea > .ant-input {
    resize: none;
    padding: 15px 12px 15px 16px;
    gap: 10px;
    height: 142px;
  }
  .ant-modal-footer {
    padding: 0 30px 30px 0;
    border-top: none;
  }
  .ant-btn-text {
    border: none;
    font-style: normal;
    font-weight: 500;
    font-size: 14px;
    line-height: 17px;
    background: none;
    text-transform: uppercase;
    color: rgba(61, 61, 61, 0.7);
  }
  .ant-btn-text:hover {
    color: rgb(61 61 61 / 45%);
  }
  .ant-form-item-explain-error {
    visibility: hidden;
  }
`;

const StyledInput = styled(Input)`
  height: 48px;
  border: 1px solid rgba(61, 61, 61, 0.5);
  border-radius: 4px;
  padding: 5px 12px 5px 16px;
  gap: 10px;
}
`;

const StyledProjectForm = styled(Form)`
  padding-left: 10%;
  .ant-form-item-explain-error {
    font-style: normal;
    font-weight: 400;
    font-size: 12px;
    line-height: 15px;
    display: flex;
    align-items: center;
  }
`;

const StyledSidebar = styled(Sider)`
  position: fixed;
  width: 100%;
  z-index: 2;
  margin-top: 64px;
  box-shadow: 0px 4px 4px rgba(0, 0, 0, 0.25);
  background: white;

  .ant-layout-sider-trigger {
    background: #1b33d5;
  }

  .ant-menu-root {
    height: calc(100vh - 114px); // header 64px footer 50px
    overflow-y: auto;
    overflow-x: hidden;
  }
`;

const StyledTitle = styled.span`
  font-size: 20px;
  font-weight: 600;
  font-color: black;
  padding-left: 20px;
`;

const StyledTabs = styled(Tabs)`
  .ant-tabs-ink-bar {
    position: absolute;
    background: black;
  }
  .ant-tabs-tab.ant-tabs-tab-active .ant-tabs-tab-btn {
    color: #363636 !important;
    font-weight: 500;
  }
  .ant-tabs-tab {
    color: grey !important;
    font-size: 14px;
    padding: 0;
  }
  .ant-tabs-nav:before {
    border-bottom: 0;
  }
`;

const StyledLink = styled(Link)`
  display: block;
  padding: 12px 0;
  color: #3d3d3d;
  font-weight: 600;
  opacity: ${({ active }) => (active ? '100%' : '60%')};
`;

const StyledP = styled.p`
  font-size: 14px;
  color: grey;
  padding-left: 20px;
`;

const StyledTab = styled(Tabs.TabPane)`
  padding: 0;
`;

const StyledAutoCompleteSelect = styled(Select)`
  width: 100%;

  .ant-select-selector {
    display: flex;
    justify-content: flex-start;
    align-items: center;
    height: 48px !important;
    border-radius: 4px !important;
  }
`;

const CustomerAutocompleteSearch = styled(Input)`
  width: 95%;
  margin: 10px 10px 10px 10px;
`;

const PopUpDivider = styled(Divider)`
  margin: 0;
`;

const NotFoundComponent = styled.div`
  display: flex;
  flex-direction: column;
  flex-wrap: wrap;
  justify-content: center;
  align-items: stretch;
  align-content: stretch;
  background: white;
  min-height: calc(100vh - 114px); // header 64px footer 50px
  width: 100%;
`;

const NotFoundImg = styled.div`
  background-image: url(${NOT_FOUND_AND_UNDER_CONSTRACT.NOT_FOUND_IMAGE});
  height: 600px;
  background-position: center;
  background-repeat: no-repeat;
  background-size: cover;

  @media (min-width: 300px) and (max-width: 400px) {
    width: 100%;
  }
`;

const NotFoundH1 = styled.h1`
  font-weight: 800;
  color: #383a41;
  text-align: center;
  font-size: 70px;
  padding-top: 20px;
`;

const NotFoundContainerBox = styled.div`
  display: flex;
  flex-direction: column;
  flex-wrap: wrap;
  justify-content: center;
  align-items: center;
  align-content: center;
  margin-top: -150px;
`;

const NotFoundH3 = styled.h3`
  font-weight: 300;
  font-size: 20px;
  text-transform: full-width;
  @media (min-width: 320px) and (max-width: 400px) {
    color: #383a41;
    text-align: center;
    font-size: 15px;
    font-weight: 300;
  }
`;

const NotFoundDescription = styled.p`
  font-weight: 600;
  color: #383a41;
  text-align: center;
  font-size: 30px;
  padding-top: 10px;
  text-transform: full-width;
  @media (min-width: 320px) and (max-width: 400px) {
    font-weight: 800;
    font-size: 15px;
    padding-top: 20px;
  }
`;

const UnderConstractComponent = styled(NotFoundComponent)`
  display: flex;
  flex-direction: column;
  flex-wrap: wrap;
  justify-content: center;
  align-items: center;
  align-content: center;
  width: 100%;

  @media (min-width: 300px) and (max-width: 600px) {
    p {
      font-weight: 300;
      font-size: 1 em;
    }
  }
`;

const UnderConstractContainer = styled.div`
  display: flex;
  flex-direction: column;
  flex-wrap: wrap;
  justify-content: center;
  align-items: center;
  align-content: center;
`;

const UnderConstractImg = styled.div`
  width: 600px;
  height: 500px;
  background: url(${NOT_FOUND_AND_UNDER_CONSTRACT.UNDER_CONSTRACT_IMAGE});
  background-size: cover;
  background-position: center;
  background-repeat: no-repeat;

  @media (min-width: 300px) and (max-width: 600px) {
    width: 70%;
    height: 163px;
  }
`;

const UnderConstractH1 = styled.h1`
  font-weight: 800;
  color: #383a41;
  text-align: center;
  font-size: 70px;
  text-transform: uppercase;

  @media (min-width: 300px) and (max-width: 600px) {
    font-weight: 800;
    color: #383a41;
    text-align: center;
    font-size: 24px;
  }
`;

const UnderConstractDescription = styled.p`
  font-weight: 800;
  color: #383a41;
  text-align: center;
  font-size: 20px;
  text-transform: full-width;

  @media (min-width: 300px) and (max-width: 600px) {
    font-size:15px;
  },
`;

const CustomerSectionLayout = styled(Layout)`
  border-radius: 4px;
  font-style: normal;
  font-weight: 400;
  font-size: 12px;
  line-height: 15px;
  color: #3d3d3d;
  padding: 0px 10px;
  background: #f1f2f6;

  .ant-form-item-explain-error {
    visibility: hidden;
  }
`;

const CustomerSectionCard = styled(Card)`
  background: white;
  border-radius: 4px;
  font-style: normal;
  font-weight: 400;
  font-size: 12px;
  line-height: 15px;
  color: #3d3d3d;
  padding: 0px 10px;
  margin: 0 auto;
  width: 100%;

  max-width: 1024px;
  min-height: 450px;

  flex-shrink: 1;
  align-self: stretch;

  .ant-card-head {
    font-weight: 600;
    font-size: 20px;
    line-height: 24px;
    border-bottom: none;
    margin: 10px 0px 5px 0px;
  }
  .ant-card-bordered {
    box-shadow: 0px 2px 8px rgba(0, 0, 0, 0.05);
    border-radius: 6px;
  }
`;

const CustomerSectionButtonDiv = styled.div`
  display: flex;
  justify-content: end;
  align-items: center;
`;

const CustomerSectionButton = styled(Button)`
  border: none;
  font-style: normal;
  font-weight: 500;
  font-size: 14px;
  line-height: 17px;
  background: none;
  text-align: center;
  letter-spacing: 0.75px;
  text-transform: uppercase;
  margin: 9px 16px;

  :hover {
    color: #40a9ff;
  }
`;
const SectionButtonDiscard = styled(CustomerSectionButton)`
  background: none;
  color: #3d3d3d;
  :hover {
    color: #777777;
  }
  :focus {
    color: rgba(100, 100, 100, 1);
  }
`;
const SectionButtonSave = styled(CustomerSectionButton)`
  border: none;
  background: none;

  :hover {
    color: #1b33d5;
  }
`;
const CustomerSectionInput = styled(StyledInput)`
  border: 1px solid rgba(0, 0, 0, 0.2);
  border-radius: 4px;
`;

const CustomerSectionCountryInput = styled(CountryPhoneInput)`
  height: 50px;
  border-radius: 4px;
  border: 1px solid rgba(0, 0, 0, 0.2);
`;

const CustomerSectionTextArea = styled(TextArea)`
  height: 142px;

  .ant-input {
    height: 142px;
    resize: none;
    padding: 15px 12px 15px 16px;
  }
`;

const EditTooltip = styled(Tooltip)`
  width: 45px;
  height: 45px;
  background: #1b33d5;
  box-shadow: 0px 4px 4px rgba(0, 0, 0, 0.25);
  color: white;

  :hover {
    background: #1b33d5;
    color: black;
  }
`;

const EditTooltipWrapper = styled('div')`
  display: flex;
  justify-content: flex-end;
`;

const ProjectLayout = styled(Layout)`
  display: flex;
  justify-content: flex-start;
  align-items: stretch;
  flex-direction: column;
  flex-wrap: nowrap;
  align-content: stretch;
  padding: 24px 12px 19px 20px;
  gap: 15px;
  background: #fafafa;
`;

const ContentComponent = styled(Content)`
  margin: 64px 0 0 ${({ collapsed }) => (collapsed ? 80 : 200)}px;
  transition: margin 0.4s;
  min-height: calc(100vh - 114px); // header 64px footer 50px
`;

const AgentIcon = styled.img.attrs({ src: agent })`
  width: 24px;
  height: 24px;
  margin: 0px 4px 0px 0px;
  vertical-align: bottom;
`;

const CustomerIcon = styled.img.attrs({ src: customer })`
  width: 24px;
  height: 24px;
  margin: 0px 4px 0px 0px;
  vertical-align: -7px;
`;
const BsCheckCircleFillIcon = styled(BsCheckCircleFill)`
  width: 18px;
  height: 18px;
  color: white;
  margin: 0px 4px 0px 0px;
  vertical-align: bottom;
`;
const BsPlusIcon = styled(BsPlus)`
  width: 22px;
  height: 22px;
`;

const CreateButtonText = styled.p`
  margin: 0;
`;
const AccountLeadIcon = styled.img.attrs({ src: accountLead })`
  width: 24px;
  height: 24px;
  margin: 0px 4px 0px 0px;
  vertical-align: -5px;
`;
const ProjectManagerIcon = styled.img.attrs({ src: projectManager })`
  width: 24px;
  height: 24px;
  margin: 0px 4px 0px 0px;
  vertical-align: bottom;
`;
const TeamLeadIcon = styled.img.attrs({ src: teamLead })`
  width: 24px;
  height: 24px;
  margin: 0px 4px 0px 0px;
  vertical-align: bottom;
`;

const TableFilterIcon = styled.img.attrs({ src: tableFilter })`
  width: 23px;
  height: 23px;
`;

const BillableIcon = styled.img.attrs({ src: billable })`
  width: 18px;
  height: 18px;
  color: white;
  margin: 0px 4px 0px 0px;
  vertical-align: bottom;
`;
const MdFilterListIcon = styled(MdFilterList)`
  width: 23px;
  height: 23px;
`;
const PageHeaderComponent = styled(PageHeader)`
  padding: 0;
  margin: 0 0 32px 0;
  max-width: 1054px;

  .ant-page-header-heading-title {
    font-size: 30px;
  }
  .ant-descriptions-item-label:after {
    content: '';
  }

  .ant-picker-input > ::placeholder {
    color: #3Dd3d3d;
  }
`;

const CarouselHeaderTitle = styled(NotFoundH3)`
  overflow-wrap: break-word;
  font-style: normal;
  font-weight: 600;
  font-size: 16px;
  line-height: 20px;
  color: white;
  text-overflow: ellipsis;
  overflow: hidden;
  white-space: nowrap;
  max-width: 260px;
`;

const CarouselDiscription = styled.div`
  white-space: nowrap;
  overflow: hidden;
  text-overflow: ellipsis;
  overflow-wrap: break-word;
  color: #3d3d3d;
  font-style: normal;
  font-weight: 500;
  font-size: 14px;
  line-height: 17px;
  display: block;
  align-items: center;
  max-width: 260px;
`;

const CarouselHeaderContent = styled(NotFoundH3)`
  overflow-wrap: break-word;
  color: white;
  font-style: normal;
  font-weight: 500;
  font-size: 14px;
  line-height: 17px;
  display: block;
  align-items: center;
  text-overflow: ellipsis;
  overflow: hidden;
  max-width: 250px;
  white-space: nowrap;
`;
const SlideLayoutComponent = styled(Card)`
  .ant-card-body {
    padding: 0;
    margin: 0px 0px 24px 0px;
  }
  @media (min-width: 250px) and (max-width: 1200px) {
    .ant-card-body {
      padding: 10px 30px 0px 0px;
    }
  }
  .react-multi-carousel-item {
    border-radius: 6px;
  }
  .react-multi-carousel-list {
    position: unset;
  }
  .react-multiple-carousel__arrow {
    width: 20px;
    height: 20px;
    z-index: 0;
    border-radius: 0px;
  }
  .react-multiple-carousel__arrow--left {
    left: calc(1% - 100px);
  }
  .react-multiple-carousel__arrow--right {
    right: calc(1% - 20px);
  }
  .react-multi-carousel-dot-list {
    bottom: -16px;
    right: calc(1% - 12vw);
  }
  .react-multi-carousel-dot {
    display: flex;
    align-items: center;
  }
  background: #fafafa;
  border: unset;

  .react-multiple-carousel__arrow--left {
    left: calc(1% - 15px);
  }
  .react-multiple-carousel__arrow--right {
    right: calc(1% - 5px);
  }
  .react-multiple-carousel__arrow {
    background: #1b33d5;
    min-width: 30px;
    min-height: 30px;
  }
  .react-multiple-carousel__arrow:hover {
    background: blue;
  }

  .react-multi-carousel-dot > button {
    border: solid 2px #e4e6f6;
    width: 6px;
    height: 6px;
  }

  .react-multi-carousel-dot--active > button {
    background: #1b33d5;
    border: solid 2px #1b33d5;
    width: 6px;
    height: 6px;
  }
`;

const SlideLayoutButton = styled.button`
  display: flex;
  flex-direction: row;
  justify-content: center;
  align-items: center;
  gap: 10px;
  width: 100%;
  height: 100%;
  min-height: 324px;
  max-width: 185px;
  word-wrap: break-word;
  border: 1px dashed #2980b9;
  background: rgba(27, 51, 213, 0.03);

  :hover {
    background: rgba(255, 255, 255, 0.5);
  }
  @media (min-width: 300px) and (max-width: 600px) {
    font-size: 8px;
    word-wrap: break-word;
  },

`;

const CarouselItem = styled(Card)`
  display: flex;
  justify-content: flex-start;
  align-items: stretch;
  flex-direction: column;
  flex-wrap: nowrap;
  align-content: stretch;
  border-radius: 4px;
  min-height: 325px;
  max-height: 325px;
  margin: 0 16px 0 0;

  .ant-card-body {
    padding: 0px;
    margin: 0;
  }
`;
const CarouselItemHeader = styled.div`
  display: flex;
  justify-content: space-between;
  align-items: stretch;
  flex-direction: row;
  flex-wrap: nowrap;
  align-content: stretch;
  background: ${({ backgroundColor }) => {
    if (backgroundColor === 0) {
      return '#1b33d5';
    } else if (backgroundColor === 1) {
      return '#FFCA28';
    } else {
      return '#8474D6';
    }
  }};
  height: 100%;
  min-height: 120px;
  padding: 15px 15px 0px 15px;
  border-radius: 4px;
  border: 1px solid ${({ backgroundColor }) => backgroundColor || '#8474D6'}
  gap: 5px;
  max-height: 120px;
  width: 100%;
`;

const CarouselItemBody = styled.div`
  display: flex;
  grid-row-gap: 8px;
  justify-content: flex-start;
  align-items: stretch;
  flex-direction: column;
  height: 100%;
  padding: 15px;
  margin: 16px 0 0 0;
  height: 196px;
`;

const TableListComponent = styled(Table)`
  .anticon {
    color: black;
  }
`;

const ProjectSectionLayout = styled(Layout)`
  border-radius: 4px;
  font-weight: 400;
  font-size: 12px;
  line-height: 15px;
  color: #3d3d3d;
  background: #fafafa;
}
`;

const ProjectSectionCard = styled(Card)`
  background: white;
  border-radius: 4px;
  font-weight: 400;
  font-size: 12px;
  line-height: 15px;
  color: #3d3d3d;
  padding: 0px 10px;
  width: 100%;
  box-shadow: 0 4px 4px rgba(0, 0, 0, 0.25);
  margin: auto;
  max-width: 1054px;
  min-height: 450px;

  flex-shrink: 1;
  align-self: stretch;

  .ant-card-head {
    font-weight: 600;
    font-size: 20px;
    line-height: 24px;
    border-bottom: none;
    margin: 10px 0px 5px 0px;
  }
  .ant-card-bordered {
    box-shadow: 0px 2px 8px rgba(0, 0, 0, 0.05);
    border-radius: 6px;
  }
`;

const CalendarDatePicker = styled(DatePicker)`
  width: 100%;
  border: 1px solid rgba(0, 0, 0, 0.2);
  border-radius: 4px;
  height: 48px;
`;

const SelectField = styled(Select)`
  width: 100%;
  border-radius: 4px;

  .ant-select-selector {
    display: flex;
    justify-content: flex-start;
    align-items: center;
    height: 48px !important;
    border-radius: 4px !important;
  }

  .ant-select-single .ant-select-selector {
    padding: 0;
    line-height: 50px !important;
  }
`;

const InputField = styled(Input)`
  width: 100%;
  height: 48px;
  border-radius: 4px;
`;

const AutoCompleteField = styled(AutoComplete)``;

const CopyRigthText = styled.p`
  margin: 0 10px;
  display: -webkit-box;
  line-clamp: 2;
  -webkit-line-clamp: 2;
  -webkit-box-orient: vertical;
  overflow: hidden;
`;

const ProfileLayout = styled(Card)`
  background: #f0f2f5;
  max-width: 1200px;
  min-width: 1024px;
  .ant-card-body {
    padding: 0;
  }
  @media (min-width: 300px) and (max-width: 800px) {
    margin: 0 12px 20px 0;
  }
`;

const ProfileCards = styled(Card)`
  width: 100%;
  height: 100%;
  word-wrap: break-word;
  .ant-card-head {
    font-weight: 500;
    font-size: 16px;
    line-height: 18px;
    border-bottom: none;
  }

  .ant-card-body {
    padding: 0;
  }
`;

const ProfileCard = styled(Card)`
  background: white;
  width: 100%;
  height: 100%;
  font-style: normal;
  font-weight: 500;
  font-size: 16px;
  line-height: 20px;
  word-wrap: break-word;
  color: #3d3d3d;
  border: 1px solid #ffffff;

  .ant-card-head {
    font-weight: 500;
    font-size: 16px;
    line-height: 18px;
    border-bottom: none;
  }

  .ant-card-body {
    padding: 0 10px 0 10px;
  }
`;

const ProfileTabAbout = styled(Card)`
  background: white;
  width: 100%;
  height: 100%;
  min-height: 350px;
  border-radius: 4px;
  word-wrap: break-word;
  font-style: normal;
  font-weight: 500;
  font-size: 16px;
  line-height: 20px;
  color: #3d3d3d;

  .ant-card-head {
    font-weight: 600;
    font-size: 20px;
    line-height: 24px;
    border-bottom: none;
    margin: 10px 0px 5px 0px;
  }
  .ant-card-bordered {
    box-shadow: 0px 2px 8px rgba(0, 0, 0, 0.05);
    border-radius: 6px;
  }
`;

const ProfilePagePicture = styled.img.attrs({ src: profilePicture })`
  width: 100%;
`;

const PaginationComponent = styled.div`
  display: flex;
  flex-direction: row;
  justify-content: flex-end;
`;

const MainWrapper = styled(Layout)`
  background: #fafafa;
`;

const TableComponent = styled(Table)`
  padding: auto 0;
  margin: 20px 0 0 0;
  width: 100%;

  .ant-table-thead {
    height: 60px;
    font-style: normal;
    font-size: 14px;
    line-height: 17px;
    color: #3d3d3d;
  }

  .ant-table-column-title {
    font-style: normal;
    font-weight: 600;
    font-size: 14px;
    line-height: 17px;
    font-weight: 600;
    z-index: 0;
    flex-grow: 0;
  }

  .ant-table-filter-column {
    display: flex;
    justify-content: flex-start;
  }

  .ant-table-thead > tr > th {
    border: none;
  }

  .ant-table-cell {
    background: white;
    font-weight: 400;
  }

  .ant-table-row {
    height: 51px;
    width: 1133px;
    padding: 17px, 16px, 17px, 16px;
    font-style: normal;
    font-size: 14px;
    line-height: 17px;
  }

  .ant-table-thead
    > tr
    > th:not(:last-child):not(.ant-table-selection-column):not(.ant-table-row-expand-icon-cell):not([colspan]):before {
    width: 0;
  }
`;

const PageContainer = styled.div`
  max-width: 1120px;
  margin: auto;
`;

const PageContainerEdit = styled(PageContainer)`
  padding: 24px 0 0 0;
`;

export {
  Logo,
  NotificationButton,
  NotificationIcon,
  Placeholder,
  Container,
  StyledCustomerSectionModal,
  StyledInput,
  StyledProjectForm,
  StyledSidebar,
  StyledAutoCompleteSelect,
  CustomerAutocompleteSearch,
  PopUpDivider,
  UnderConstractComponent,
  UnderConstractContainer,
  UnderConstractH1,
  UnderConstractImg,
  UnderConstractDescription,
  NotFoundComponent,
  NotFoundImg,
  NotFoundH1,
  NotFoundContainerBox,
  NotFoundH3,
  NotFoundDescription,
  ProjectLayout,
  CustomerSectionLayout,
  CustomerSectionCard,
  CustomerSectionButtonDiv,
  CustomerSectionButton,
  SectionButtonSave,
  SectionButtonDiscard,
  CustomerSectionInput,
  CustomerSectionCountryInput,
  CustomerSectionTextArea,
  EditTooltip,
  EditTooltipWrapper,
  ProjectSectionLayout,
  ProjectSectionCard,
  CalendarDatePicker,
  CopyRigthText,
  InputField,
  SelectField,
  AutoCompleteField,
  StyledLink,
  StyledP,
  StyledTab,
  StyledTabs,
  StyledTitle,
  MdFilterListIcon,
  BillableIcon,
  TeamLeadIcon,
  TableFilterIcon,
  ProjectManagerIcon,
  AccountLeadIcon,
  BsCheckCircleFillIcon,
  AgentIcon,
  CustomerIcon,
  BsPlusIcon,
  CreateButtonText,
  CarouselHeaderTitle,
  CarouselHeaderContent,
  CarouselDiscription,
  PageHeaderComponent,
  SlideLayoutComponent,
  SlideLayoutButton,
  CarouselItem,
  CarouselItemHeader,
  CarouselItemBody,
  TableListComponent,
  ProfileLayout,
  ProfileTabAbout,
  ProfileCard,
  ProfileCards,
  ProfilePagePicture,
  PaginationComponent,
  MainWrapper,
  TableComponent,
  ContentComponent,
  PageContainer,
  PageContainerEdit,
};
