import React from 'react';
import PropTypes from 'prop-types';
import { Col } from 'antd';
import {
  CustomerInfoDescription,
  CustomerInfoRow,
  CustomerInfoStyled,
} from './Styled';
import { useIntl } from 'react-intl';
import locale from './locale';

const CustomerInfo = ({ customer }) => {
  const { formatMessage } = useIntl();
  const { name, address, phone, email } = customer;

  return (
    <CustomerInfoStyled title={formatMessage(locale.customerTitle)}>
      <CustomerInfoRow gutter={[24, 16]}>
        <Col span={6}>{formatMessage(locale.customerName)}</Col>
        <CustomerInfoDescription span={18}>{name}</CustomerInfoDescription>
      </CustomerInfoRow>
      <CustomerInfoRow gutter={[24, 16]}>
        <Col span={6}>{formatMessage(locale.customerAddress)}</Col>
        <CustomerInfoDescription span={18}>{address}</CustomerInfoDescription>
      </CustomerInfoRow>
      <CustomerInfoRow gutter={[24, 16]}>
        <Col span={6}>{formatMessage(locale.customerPhone)}</Col>
        {/* TODO: format */}
        <CustomerInfoDescription span={18}>{phone}</CustomerInfoDescription>
      </CustomerInfoRow>
      <CustomerInfoRow gutter={[24, 16]}>
        <Col span={6}>{formatMessage(locale.customerEmail)}</Col>
        <CustomerInfoDescription span={18}>{email}</CustomerInfoDescription>
      </CustomerInfoRow>
    </CustomerInfoStyled>
  );
};

CustomerInfo.propTypes = {
  customer: PropTypes.exact({
    id: PropTypes.number.isRequired,
    name: PropTypes.string.isRequired,
    email: PropTypes.string.isRequired,
    address: PropTypes.string.isRequired,
    phone: PropTypes.string,
  }),
};

export default CustomerInfo;
