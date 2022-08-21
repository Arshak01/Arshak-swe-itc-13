import { listAll } from '../api/meta';

export const GET_META_INFO = 'META/GET_META_INFO';

export const getMeta = () => async (dispatch) => {
  const data = await listAll();
  return dispatch({
    type: GET_META_INFO,
    payload: data,
  });
};

export default {
  getMeta,
};
