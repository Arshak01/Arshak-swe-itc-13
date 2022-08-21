import axios from 'axios';
import { EMPLOYEES_API } from '../utils/constants';

export const listAll = (params) =>
  axios.get(EMPLOYEES_API, { params }).then((res) => res.data);

export default {
  listAll,
};
