import styled from 'styled-components';
import Icon, { PaperClipOutlined } from '@ant-design/icons';
import { Card, DatePicker, Input, Select, Typography } from 'antd';
import CountryPhoneInput from 'antd-country-phone-input';

const { Title } = Typography;
const { RangePicker } = DatePicker;

export const SectionCard = styled(Card)`
  background: white;
  border-radius: 4px;
  font-weight: 400;
  font-size: 12px;
  line-height: 15px;
  color: #3d3d3d;
  margin-bottom: 20px;
  box-shadow: 0 2px rgba(0, 0, 0, 0.05);
  padding: 0;

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
    box-shadow: 0px 2px rgba(0, 0, 0, 0.05);
    border-radius: 6px;
  }
  .ant-card-body {
    padding: 15px 16px;
  }
`;

export const ActionsButtonSection = styled.div`
  display: flex;
  justify-content: right;
  align-items: center;
`;

export const UploadIcon = styled(PaperClipOutlined)`
  width: 20px;
`;

export const UploadWrapper = styled.div`
.ant-upload.ant-upload-drag {
    height: 48px;
    border: 1px dashed rgba(61, 61, 61, 0.5);
    border-radius: 4px;
    padding 4px 11px;
    background: unset;
 }
 .ant-upload.ant-upload-drag:hover {
    border: 1px dashed #2980b9;
 }
 .ant-upload.ant-upload-btn {
    border-radius: 4px;
    height: 100%;
    padding: 0;
  }
  .ant-upload .ant-upload-drag-container {
    display: flex;
    flex-direction: row;
    justify-content: space-between;
    align-items: center;
    color: gray;
    height: 100%;
  }
`;

export const StyledTextArea = styled(Input.TextArea)`
  width: 100%;
  height: 120px;
  border-radius: 4px;
  color: #3d3d3d;
  opacity: ${({ focus }) => (focus ? '100%' : '60%')};
  > .ant-input {
    resize: none;
  }
`;

export const SectionTitle = styled(Title)`
  &.ant-typography {
    color: #3d3d3d;
    padding: 0 5px 10px;
  }
`;

export const StyledRangePicker = styled(RangePicker)`
  width: 100%;
  height: 48px;
  color: #3d3d3d;
  opacity: ${({ focus }) => (focus ? '100%' : '60%')};
  border-radius: 4px;
  border: 1px solid rgba(61, 61, 61, 0.5);
  .ant-picker-suffix {
    margin-left: 1px;
    margin-right: 10px;
    order: -1;
  }
`;

export const PhoneInput = styled(CountryPhoneInput)`
  height: 48px;
  border: 1px solid rgba(0, 0, 0, 0.2);
  color: #3d3d3d;
  opacity: ${({ focus }) => (focus ? '100%' : '60%')};
`;

export const InputField = styled(Input)`
  width: 100%;
  height: 48px;
  border-radius: 4px;
  color: #3d3d3d;
  opacity: ${({ focus }) => (focus ? '100%' : '60%')};
`;

export const SelectField = styled(Select)`
  width: 100%;
  border-radius: 4px;
  color: #3d3d3d;
  opacity: ${({ focus }) => (focus ? '100%' : '60%')};

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
  .ant-select-clear {
    padding-right: 10px;
    width: 20px;
  }
`;

export const DropDownIcon = styled(Icon)`
  color: black;
  padding-right: 10px;
  font-size: 10px;
`;
