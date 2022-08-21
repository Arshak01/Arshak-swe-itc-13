import { API } from '../utils/constants';
import axios from 'axios';

const addCustomers = (values) => {
  return axios
    .post(API.CUSTOMERS_API, values)
    .then((response) => response.data)
    .catch((error) => error);
};

const getCustomers = () => {
  return axios
    .get(API.CUSTOMERS_API)
    .then((response) => response.data)
    .catch((error) => error);
};

export { addCustomers, getCustomers };
