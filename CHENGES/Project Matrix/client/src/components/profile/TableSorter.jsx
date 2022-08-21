import React from 'react';
import PropTypes from 'prop-types';
import { useIntl } from 'react-intl';
import { SortIcon, TableHeaderCell } from './Styled';
import locale from './locale';

const TableSorter = ({ /*sortColumn */ dataIndex }) => {
  const { formatMessage } = useIntl();
  const mapDataIndexToTile = (dataIndex) => {
    switch (dataIndex) {
      case 'employeeFullName':
        return formatMessage(locale.nameSurname);
      case 'startDate':
        return formatMessage(locale.period);
      case 'branch':
        return formatMessage(locale.branch);
      case 'position':
        return formatMessage(locale.position);
      case 'rate':
        return formatMessage(locale.actualRate);
    }
  };

  return (
    <TableHeaderCell>
      {mapDataIndexToTile(dataIndex)}
      <SortIcon />
    </TableHeaderCell>
  );
};

TableSorter.propTypes = {
  dataIndex: PropTypes.string.isRequired,
  sortColumn: PropTypes.string.isRequired,
};

export default TableSorter;
