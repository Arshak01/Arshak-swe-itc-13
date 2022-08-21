import styled from 'styled-components';
import { Card, Col, Row, Select, Switch, Table, Typography } from 'antd';
import sortIcon from '../../asserts/sort.svg';

const { Paragraph } = Typography;

export const EditToolButtonPositioned = styled.div`
  position: absolute;
  top: -61px;
  right: 0;
`;

export const ProfileLayout = styled.div`
  /* background: #f0f2f5; */
  /* max-width: 1200px;
  min-width: 1024px; */
  position: relative;
  .ant-card-body {
    padding: 0;
  }
`;

export const ProfileCards = styled(Card)`
  width: 100%;
  height: 100%;
  word-wrap: break-word;
  text-transform: capitalize;

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

export const ProfileCard = styled(Card)`
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

export const ProfileTabAbout = styled(Card)`
  background: white;
  width: 100%;
  height: 310px;
  border-radius: 4px;
  word-wrap: break-word;
  font-weight: 400;
  font-size: 16px;
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
export const ProfilePagePicture = styled.img`
  width: 100%;
`;

export const ColDescription = styled(Col)`
  font-weight: 800;
  font-size: 14px;
  display: flex;
  align-items: center;
  color: black;
`;

export const ColDescriptionBudget = styled(ColDescription)`
  font-weight: 600;
  color: #4caf50;
`;

export const ColWithBorder = styled(Col)`
  border-left: 1px solid #777777;
  font-style: normal;
  font-size: 14px;
  align-items: center;
  color: #000000;
  display: flex;
  justify-content: space-between;
  padding-left: 10px !important;
`;

export const RowWithBorder = styled(Row)`
  border-bottom: 1px solid #b1b1b1;
  padding: 12px 0;
`;

export const ProjectInfoStyled = styled(Card)`
  background: white;
  width: 100%;
  ${({ noMargin }) => !noMargin && 'margin: 0 0 20px 0'};
  border-radius: 4px;
  font-weight: 500;
  font-size: 16px;
  color: #3d3d3d;

  .ant-card-head {
    font-weight: 500;
    font-size: 16px;
    line-height: 24px;
    border-bottom: none;
    margin: 0;
    padding: 12px 16px 8px;
    min-height: unset;
  }
  &.ant-card-bordered {
    border: none;
    border-radius: 6px;
    box-shadow: ${({ withBorder }) =>
      withBorder ? '0px 2px 8px rgba(0, 0, 0, 0.05)' : 'none'};
  }
  .ant-card-body {
    padding: 0 22px 4px 16px;
  }
  .ant-card-head-title {
    padding: 0;
    text-transform: capitalize;
    font-weight: 600;
  }
`;

export const CustomerInfoStyled = styled(Card)`
  background: white;
  width: 100%;
  margin: 0 0 20px 0;
  border-radius: 4px;
  font-size: 16px;
  color: #3d3d3d;
  padding: 40px 16px 12px 16px;

  .ant-card-head {
    font-weight: 600;
    font-size: 16px;
    border-bottom: none;
    padding: 0 0 16px;
    min-height: unset;
    text-transform: capitalize;
  }
  .ant-card-bordered {
    box-shadow: 0px 2px 8px rgba(0, 0, 0, 0.05);
    border-radius: 6px;
  }
  .ant-card-head-title {
    padding: 0;
  }
`;

export const CustomerInfoRow = styled(Row)`
  padding-bottom: 12px;
`;

export const CustomerInfoDescription = styled(Col)`
  font-weight: 600;
  font-size: 14px;
  color: black;
`;

export const StyledText = styled(Paragraph)`
  &.ant-typography {
    font-size: 14px;
    line-height: 1.3;
    margin: 0;
  }
`;

export const TeamInfoRow = styled(Row)`
  margin-bottom: 12px;
`;

export const About = styled(Row)`
  background-color: #ffffff;
`;

export const AllocationHistoryTable = styled(Table)`
  margin-top: 20px;
  tbody {
    box-shadow: 0px 4px 4px rgb(0 0 0 / 25%);
  }
  .ant-table-title {
    font-weight: 600;
    font-size: 16px;
  }
  .ant-table {
    color: #3d3d3d;
  }
  .ant-table-column-sorter {
    display: none;
  }
  .ant-table-thead th.ant-table-column-sort {
    background: #ffffff;
  }
  td.ant-table-column-sort {
    background: #ffffff;
  }
  .ant-table-thead > tr > th {
    font-weight: 600;
  }
  .ant-table-thead > tr > th,
  .ant-table-tbody > tr:not(:last-of-type) > td {
    border-bottom: 0.5px solid #636363;
  }
  .ant-table-thead > tr > th:before {
    width: 0;
  }
`;

export const ConfidentialTypeSelect = styled(Select)`
  width: 100%;
  color: ${({ color }) => color};
  /* TODO */
  height: 25px;
  align-items: center;
  display: flex;
  &.ant-select > .ant-select-selector {
    padding: 0;
  }
  & > .ant-select-single:not(.ant-select-customize-input) .ant-select-selector {
    height: 25px;
  }
  .ant-select-single .ant-select-selector .ant-select-selection-item:after {
    display: none;
  }
`;

export const TableHeaderCell = styled.div`
  display: flex;
`;

export const SortIcon = styled.img.attrs({ src: sortIcon })`
  margin-left: 10px;
  ${({ rotate }) => rotate && 'transform: rotateX(180deg) rotateY(0deg)'};
`;

export const TableTitle = styled(Text)``;

export const GreenSwitch = styled(Switch)`
  &.ant-switch-checked {
    background: #66bb6a;
  }
`;
