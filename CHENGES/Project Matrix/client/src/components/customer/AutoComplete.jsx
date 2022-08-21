import { PlusOutlined } from '@ant-design/icons';
import { Button } from 'antd';
import PropTypes from 'prop-types';
import React, { useCallback, useEffect, useState } from 'react';
import { useIntl } from 'react-intl';
import { useDispatch, useSelector } from 'react-redux';
import { getAllCustomers } from '../../actions/active-customers-actions';
import { customersDataSelector } from '../../selectors/customers';
import {
  CustomerAutocompleteSearch,
  PopUpDivider,
  StyledAutoCompleteSelect,
} from '../../Styled';
import AddCustomerModal from './AddCustomerModal';
import locale from './locale';

const AutoComplete = ({ onChange, name: fieldName }) => {
  const [isLoading, setIsLoading] = useState(false);
  const [isVisible, setIsVisible] = useState(false);
  const [customersList, setCustomersList] = useState([]);
  const [name, setName] = useState('');
  const [isOpen, setIsOpen] = useState();
  const [selectedCustomer, setSelectedCustomer] = useState({ label: '' });
  const { formatMessage } = useIntl();
  const customersData = useSelector(customersDataSelector);
  const dispatch = useDispatch();

  useEffect(() => {
    setIsLoading(true);
    dispatch(getAllCustomers());
    setIsLoading(false);
  }, [dispatch]);

  useEffect(() => {
    if (customersData.length) {
      setCustomersList(
        customersData.map(({ id, name }) => ({ label: name, value: id })),
      );
    }
  }, [customersData]);

  const selectCustomer = useCallback(
    (id, name) => {
      setSelectedCustomer({ label: name, value: id });
      onChange && onChange({ label: name, value: id }, fieldName);
    },
    [fieldName, onChange],
  );

  const onCreate = ({ id, name }) => selectCustomer(id, name);

  const onFilter = (e) => {
    setIsLoading(true);
    setName(e.target.value);
    setCustomersList(
      customersData
        .filter((data) =>
          data.name.toLowerCase().includes(e.target.value.toLowerCase()),
        )
        .map(({ id, name }) => ({ label: name, value: id })),
    );
    setIsLoading(false);
  };

  const handleSelect = useCallback(
    (id) => {
      const item = customersData.find((data) => data.id === id);
      if (item) {
        const { id, name } = item;
        selectCustomer(id, name);
      }
    },
    [customersData, selectCustomer],
  );

  const resetPopUp = () => {
    if (isOpen === false) {
      setIsOpen(undefined);
    }
  };

  const handleAddClick = () => setIsVisible(true);

  return (
    <>
      <StyledAutoCompleteSelect
        loading={isLoading}
        onSelect={handleSelect}
        options={customersList}
        value={selectedCustomer}
        open={isOpen}
        onClick={resetPopUp}
        dropdownRender={(menu) => (
          <>
            <CustomerAutocompleteSearch
              placeholder="Please enter name"
              value={name}
              onChange={onFilter}
            />
            {menu}
            <PopUpDivider />
            <Button type="link" onClick={handleAddClick}>
              <PlusOutlined />
              {formatMessage(locale.addNew)}
            </Button>
          </>
        )}
      />
      <AddCustomerModal
        visible={isVisible}
        onSubmit={onCreate}
        onClose={() => setIsVisible(false)}
      />
    </>
  );
};

AutoComplete.propTypes = {
  name: PropTypes.string,
  onChange: PropTypes.func,
};

export default AutoComplete;
