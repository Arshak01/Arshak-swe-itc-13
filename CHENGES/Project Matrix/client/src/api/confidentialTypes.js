import axios from 'axios';
import { API } from '../utils/constants';

const listAll = () => {
  return axios
    .get(API.CONFIDENTIAL_TYPE_API)
    .then((res) => res.data)
    .catch((error) => error);
};

export default {
  listAll,
};
