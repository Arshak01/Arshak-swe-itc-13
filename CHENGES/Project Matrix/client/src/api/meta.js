import axios from 'axios';
import { META_API } from '../utils/constants';

export const listAll = () => axios.get(META_API).then((res) => res.data);

export default {
  listAll,
};
