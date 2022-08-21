import axios from 'axios';
import { API } from '../utils/constants';

const access_token = process.env.REACT_APP_SERVER_AUTH_TOKEN;
export const checkName = (name) =>
  axios
    .get(`${API.CHECK_PROJECT_NAME_API}?name=${name}`)
    .then((res) => res.data);

const create = (project) => axios.post(API.PROJECTS_API, project);

export const listAll = (params) => {
  var config = {
    params,
    // TODO: Must be change afther sign-up and login page.
    headers: {
      Authorization: `Bearer ${access_token}`,
    },
  };

  return axios
    .get(API.PROJECTS_API, config)
    .then((res) => res.data)
    .catch((error) => error);
};

export const getByName = (name) => {
  const config = {
    headers: {
      Authorization: `Bearer ${access_token}`,
    },
  };
  return axios
    .get(`${API.PROJECTS_API}/${name}`, config)
    .then((res) => res.data)
    .catch((error) => error);
};

const update = (id, data) => {
  axios.put(`${API.PROJECTS_API}/${id}`, data);
};

export const uploadLogo = async (id, data) => {
  return axios
    .post(`${API.PROJECTS_API}/${id}/uploadLogo`, data)
    .then((res) => res.data)
    .catch((error) => error);
};

export default {
  create,
  checkName,
  listAll,
  getByName,
  update,
  uploadLogo,
};
