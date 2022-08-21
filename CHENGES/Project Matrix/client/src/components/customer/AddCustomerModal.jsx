import { Col, Input, Row, notification } from 'antd';
import { ConfigProvider } from 'antd-country-phone-input';
import { Form, Formik } from 'formik';
import PropTypes from 'prop-types';
import React from 'react';
import { useIntl } from 'react-intl';
import { useDispatch } from 'react-redux';
import en from 'world_countries_lists/data/countries/en/world.json';
import { addCustomer } from '../../actions/active-customers-actions';
import { StyledCustomerSectionModal } from '../../Styled';
import { CONSTANTS } from '../../utils/constants';
import FloatInputHOC from '../FloatInputHOC';
import { InputField, PhoneInput } from './AddCustomerStyled';
import { createValidationSchema } from './CustomerValidation.schema';
import locale from './locale';
import _ from 'lodash';

const FloatingInput = FloatInputHOC(InputField);
const FloatingTextArea = FloatInputHOC(Input.TextArea);
const FloatingPhoneInput = FloatInputHOC(PhoneInput);

notification.config({
  placement: 'bottomLeft',
});

const AddCustomerModal = ({ visible, initialValues, onSubmit, onClose }) => {
  const { formatMessage } = useIntl();
  const dispatch = useDispatch();
  const handleCreate = async (values, { resetForm }) => {
    try {
      const { payload } = await dispatch(addCustomer(values));
      onSubmit(payload);
      resetForm();
      onClose();
    } catch (error) {
      notification.error({
        message: 'Notification error',
        description: CONSTANTS.ERROR_MESSAGE,
      });
    }
  };

  const handleDiscard = (resetForm) => {
    onClose();
    resetForm();
  };

  return (
    <ConfigProvider locale={en}>
      <Formik
        initialValues={initialValues}
        validationSchema={createValidationSchema()}
        onSubmit={handleCreate}
        isValid={false}
      >
        {({
          values,
          errors,
          handleChange,
          setFieldValue,
          handleSubmit,
          resetForm,
          handleBlur,
          isSubmitting,
          isValid,
          touched,
        }) => {
          const isDisabled = _.isEmpty(touched) || !isValid;
          return (
            !isSubmitting && (
              <StyledCustomerSectionModal
                visible={visible}
                onOk={handleSubmit}
                width={'55%'}
                onCancel={() => handleDiscard(resetForm)}
                okButtonProps={{
                  type: 'link',
                  disabled: isDisabled,
                }}
                cancelButtonProps={{ type: 'text' }}
                okText={formatMessage(locale.createButton)}
                cancelText={formatMessage(locale.cancleButton)}
                closable={false}
                centered={true}
              >
                <Form>
                  <Row gutter={{ xs: 8, sm: 16, md: 24, lg: 32 }}>
                    <Col span={12}>
                      <FloatingInput
                        autoFocus={true}
                        maxLength={50}
                        name="name"
                        onChange={handleChange}
                        placeholder={formatMessage(locale.customerName)}
                        required
                        value={values.name}
                        onBlur={handleBlur}
                      />
                    </Col>

                    <Col span={12}>
                      <FloatingInput
                        maxLength={50}
                        errorMessage={errors.address}
                        name="address"
                        onChange={handleChange}
                        placeholder={formatMessage(locale.customerAddress)}
                        value={values.address}
                        onBlur={handleBlur}
                      />
                    </Col>
                  </Row>
                  <Row gutter={{ xs: 8, sm: 16, md: 24, lg: 32 }}>
                    <Col span={12}>
                      <FloatingInput
                        errorMessage={errors.email}
                        maxLength={50}
                        name="email"
                        onChange={handleChange}
                        placeholder={formatMessage(locale.customerEmail)}
                        value={values.email}
                        onBlur={handleBlur}
                      />
                    </Col>

                    <Col span={12}>
                      <FloatingPhoneInput
                        maxLength={25}
                        name="phone"
                        onChange={(e) => setFieldValue('phone', e)}
                        placeholder={formatMessage(locale.customerPhone)}
                        type="number"
                        value={values.phone}
                        onBlur={handleBlur}
                      />
                    </Col>
                  </Row>
                  <Row gutter={{ xs: 8, sm: 16, md: 24, lg: 32 }}>
                    <Col span={24}>
                      <FloatingTextArea
                        maxLength={500}
                        name="info"
                        onChange={handleChange}
                        placeholder={formatMessage(locale.customerInfo)}
                        showCount
                        value={values.info}
                        onBlur={handleBlur}
                      />
                    </Col>
                  </Row>
                </Form>
              </StyledCustomerSectionModal>
            )
          );
        }}
      </Formik>
    </ConfigProvider>
  );
};

AddCustomerModal.propTypes = {
  initialValues: PropTypes.exact({
    name: PropTypes.string,
    email: PropTypes.string,
    address: PropTypes.string,
    phone: PropTypes.exact({
      code: PropTypes.string,
      phone: PropTypes.number,
      short: PropTypes.string,
    }),
    about: PropTypes.string,
  }),
  visible: PropTypes.bool,
  onClose: PropTypes.func.isRequired,
  onSubmit: PropTypes.func,
};

AddCustomerModal.defaultProps = {
  initialValues: { phone: { short: 'US' } },
  onSubmit: () => {},
  visible: false,
};

export default AddCustomerModal;
