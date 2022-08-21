import { addCustomers, getCustomers } from '../api/customer';

export const GET_ALL_AVAILABLE_CUSTOMERS = 'GET_ALL_AVAILABLE_CUSTOMERS';
export const ADD_CUSTOMER = 'ADD_CUSTOMER';

export const getAllCustomers = () => (dispatch) =>
  getCustomers().then((data) => {
    return dispatch({
      type: GET_ALL_AVAILABLE_CUSTOMERS,
      payload: data,
    });
  });
export const addCustomer = (data) => (dispatch) =>
  addCustomers(data).then((response) => {
    return dispatch({
      type: ADD_CUSTOMER,
      payload: response,
    });
  });
