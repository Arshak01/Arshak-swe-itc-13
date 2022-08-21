import { listAll } from '../api/employees';

export const GET_EMPLOYEES_INFO = 'EMPLOYEE/GET_EMPLOYEES_INFO';

const getAllEmployees =
  (params = {}) =>
  async (dispatch) => {
    const data = await listAll(params);
    return dispatch({
      type: GET_EMPLOYEES_INFO,
      payload: { data, params },
    });
  };

export const getAccountLeads = () =>
  getAllEmployees({ position: 'account_lead' });
export const getTeamLeads = () => getAllEmployees({ position: 'team_lead' });
export const getProjectManagers = () =>
  getAllEmployees({ position: 'project_manager' });
