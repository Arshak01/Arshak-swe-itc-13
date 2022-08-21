import React from 'react';
import PropTypes from 'prop-types';
import { useIntl } from 'react-intl';
import { AllocationHistoryTable } from './Styled';
import TableSorter from './TableSorter';
import locale from './locale';

const constructEmployeeAllocations = (data) => {
  return data.map(
    ({
      id,
      start_date: startDate,
      // end_date: endDate,
      rate,
      employee: {
        hr_employee: { name, surname },
        position: { name: position },
        branch: { name: branch },
      },
    }) => ({
      id,
      startDate,
      rate,
      employeeFullName: `${name} ${surname}`,
      branch,
      position,
    }),
  );
};

const AllocationHistory = ({ employeeAllocations }) => {
  const { formatMessage } = useIntl();
  const columns = [
    {
      title: ({ sortColumn: { dataIndex } }) => (
        <TableSorter sortColumn={dataIndex} dataIndex="employeeFullName" />
      ),
      dataIndex: 'employeeFullName',
      defaultSortOrder: 'descend',
      sorter: (a, b) => a.employeeFullName.localeCompare(b.employeeFullName),
    },
    {
      title: ({ sortColumn: { dataIndex } }) => (
        <TableSorter sortColumn={dataIndex} dataIndex="startDate" />
      ),
      dataIndex: 'startDate', // TODO
      defaultSortOrder: 'descend',
      sorter: (a, b) => a.startDate.localeCompare(b.startDate), // TODO
    },
    {
      title: ({ sortColumn: { dataIndex } }) => (
        <TableSorter sortColumn={dataIndex} dataIndex="branch" />
      ),
      dataIndex: 'branch',
      defaultSortOrder: 'descend',
      sorter: (a, b) => a.branch.localeCompare(b.branch),
    },
    {
      title: ({ sortColumn: { dataIndex } }) => (
        <TableSorter sortColumn={dataIndex} dataIndex="position" />
      ),
      dataIndex: 'position',
      defaultSortOrder: 'descend',
      sorter: (a, b) => a.position.localeCompare(b.position),
    },
    {
      title: ({ sortColumn: { dataIndex } }) => (
        <TableSorter sortColumn={dataIndex} dataIndex="rate" />
      ),
      dataIndex: 'rate',
      defaultSortOrder: 'descend',
      sorter: (a, b) => a.rate - b.rate,
    },
    // TODO: add action column
  ];

  return (
    <AllocationHistoryTable
      title={() => formatMessage(locale.allocationHistory)} // TODO
      columns={columns}
      scroll={{ x: true }}
      dataSource={constructEmployeeAllocations(employeeAllocations)}
    />
  );
};

AllocationHistory.propTypes = {
  employeeAllocations: PropTypes.arrayOf(PropTypes.exact({})), // TODO
};

export default AllocationHistory;
