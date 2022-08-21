import React from 'react';
import { Row } from 'antd';
import { useNavigate } from 'react-router-dom';
import { useIntl } from 'react-intl';
import { TableComponent, TableFilterIcon } from '../../../Styled';
import locale from './locale';
import { URL_TO } from '../../../utils/constants';
import { PROP_TYPES } from '../../../utils/proptypes';

const filtersFields = (projectsList, cb) =>
  projectsList.reduce((acc, project) => {
    const value = cb(project);
    if (!acc[value]) {
      acc[value] = { value, text: value };
    }
    return acc;
  }, {});

const TableList = ({ projectsList }) => {
  const navigate = useNavigate();
  const { formatMessage } = useIntl();

  const columns = [
    {
      title: formatMessage(locale.placeholderProjectName),
      dataIndex: 'name',
      filters: Object.values(filtersFields(projectsList, ({ name }) => name)),
      filterIcon: (filtered) => (
        <TableFilterIcon style={{ color: filtered ? '#1890ff' : undefined }} />
      ),
      filterMode: 'tree',
      filterSearch: true,
      onFilter: (value, record) => {
        if (value === record.name) return record.name === value;
      },
      width: '15%',
    },
    {
      title: formatMessage(locale.placeholdeAgent),
      dataIndex: ['agent', 'name'],
      filters: Object.values(
        filtersFields(projectsList, ({ agent: { name } = {} }) => name),
      ),
      filterIcon: (filtered) => (
        <TableFilterIcon style={{ color: filtered ? '#1890ff' : undefined }} />
      ),
      filterMode: 'tree',
      filterSearch: true,
      onFilter: (value, record) => {
        if (record.agent && value === record.agent.name)
          return record.agent.name === value;
      },
      width: '15%',
    },
    {
      title: formatMessage(locale.placeholderEngagementCategory),
      dataIndex: ['engagementCategory', 'name'],
      filters: Object.values(
        filtersFields(
          projectsList,
          ({ engagementCategory: { name } = {} }) => name,
        ),
      ),
      filterIcon: (filtered) => (
        <TableFilterIcon style={{ color: filtered ? '#1890ff' : undefined }} />
      ),
      filterMode: 'tree',
      filterSearch: true,
      onFilter: (value, record) => {
        if (value === record.engagementCategory.name)
          return record.engagementCategory?.name === value;
      },
      width: '15%',
    },
    {
      title: formatMessage(locale.placeholderEngagementModel),
      dataIndex: ['engagementModel', 'name'],
      filters: Object.values(
        filtersFields(
          projectsList,
          ({ engagementModel: { name } = {} }) => name,
        ),
      ),
      filterIcon: (filtered) => (
        <TableFilterIcon style={{ color: filtered ? '#1890ff' : undefined }} />
      ),
      filterMode: 'tree',
      filterSearch: true,
      onFilter: (value, record) => {
        if (value === record.engagementModel?.name)
          return record.engagementModel?.name === value;
      },
      width: '15%',
    },
    {
      title: formatMessage(locale.placeholdeTeamLead),
      dataIndex: 'teamLead',
      filters: Object.values(
        filtersFields(projectsList, ({ teamLead }) => teamLead),
      ),
      filterIcon: (filtered) => (
        <TableFilterIcon style={{ color: filtered ? '#1890ff' : undefined }} />
      ),
      filterMode: 'tree',
      filterSearch: true,
      onFilter: (value, record) => {
        if (value === record.teamLead) return record.teamLead === value;
      },
      width: '15%',
    },
    {
      title: formatMessage(locale.placeholdeAccountLead),
      dataIndex: 'accountLead',
      filters: Object.values(
        filtersFields(projectsList, ({ accountLead }) => accountLead),
      ),
      filterIcon: (filtered) => (
        <TableFilterIcon style={{ color: filtered ? '#1890ff' : undefined }} />
      ),
      filterMode: 'tree',
      filterSearch: true,
      onFilter: (value, record) => {
        if (value === record.accountLead) return record.accountLead === value;
      },
      width: '15%',
    },
    {
      title: formatMessage(locale.placeholdeStatus),
      dataIndex: 'isActive',
      render: (val) =>
        val === true
          ? formatMessage(locale.carouselHeaderOpen)
          : formatMessage(locale.carouselHeaderClose),
      filters: [
        {
          text: formatMessage(locale.carouselHeaderOpen),
          value: true,
        },
        {
          text: formatMessage(locale.carouselHeaderClose),
          value: false,
        },
      ],
      filterIcon: (filtered) => (
        <TableFilterIcon style={{ color: filtered ? '#1890ff' : undefined }} />
      ),
      filterMultiple: true,
      filterMode: 'tree',
      filterSearch: true,
      width: '10%',
      onFilter: (value, record) => {
        if (value === record.isActive) return record.isActive === value;
      },
    },
  ];

  return (
    <Row justify="center">
      <TableComponent
        dataSource={projectsList}
        columns={columns}
        size={'small'}
        scroll={{ x: true }}
        pagination={true}
        onRow={(record) => {
          return {
            onClick: () => {
              const projectURL = URL_TO.PROJECT_PROFILE_PAGE.urlTo.replace(
                ':projectName',
                record.name.toLowerCase().trim(),
              );
              navigate(projectURL);
            },
          };
        }}
      />
    </Row>
  );
};

TableList.propTypes = PROP_TYPES.PROJECT_LIST;

export default TableList;
