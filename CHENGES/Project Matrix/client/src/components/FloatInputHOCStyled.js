import styled from 'styled-components';

export const StyledInputFieldDiv = styled.div`
  width: 100%;
  position: relative;
  height: 80px;
  margin: 5px;
  .ant-input,
  .ant-select > .ant-select-selector,
  .antd-country-phone-input {
    ${({ isError }) => isError && 'border-color: #F90606;'}
    box-shadow: none;
    border: 1px solid rgba(61, 61, 61, 0.5);
  }
  .ant-input:hover,
  .antd-country-phone-input:hover,
  .ant-picker-range:hover,
  .ant-select .ant-select-selector:hover,
  .ant-select-focused.ant-select:not(.ant-select-customize-input)
    .ant-select-selector,
  .ant-picker-focused {
    border: 1px solid #2980b9;
    box-shadow: none;
  }
  .ant-input-affix-wrapper > input.ant-input {
    border: none;
  }
`;

export const StyledFloatLabel = styled.label`
  font-style: normal;
  font-size: 12px;
  font-weight: 400;
  position: absolute;
  pointer-events: none;
  line-height: 17px;
  display: flex;
  align-items: center;
  color: gray;
  left: 10px;
  top: 15px;
  z-index: 1;
  transition: 0.2s ease all;
  ${({ isOccupied, lightLabel }) =>
    isOccupied
      ? `font-size: 12px !important;
        top: -8px;
        background: white;
        padding: 0 4px;
        margin-left: -4px;
        color: ${lightLabel ? '#3d3d3d;' : 'black'};`
      : ''}
`;

export const StyledErrorWrapper = styled.div`
  color: #f90606;
  padding: 4px 0 0 16px;
`;

export const StyledRequireMark = styled.span`
  color: #ff4d4f;
  margin-left: 2px;
`;
