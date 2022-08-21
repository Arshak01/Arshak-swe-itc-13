import projectApi from '../api/projects';

export const TABLE_SORT_COLUMN = 'TABLE_SORT_COLUMN';
export const TABLE_NEXT_PAGE = 'TABLE_NEXT_PAGE'; // TODO: action names are draft
export const TABLE_PAGE_TOTAL_COUNT = 'TABLE_TOTAL_PAGE_COUNT';
export const TABLE_PAGE_COUNT = 'TABLE_PAGE_COUNT';
export const CREATE_PROJECT = 'PROJECT/CREATE_PROJECT';
export const CREATE_PROJECT_START = 'PROJECT/CREATE_PROJECT_START';
export const GET_ALL_PROJECT = 'PROJECT/GET_ALL_PROJECT';
export const GET_ALL_TABLE_PROJECT = 'PROJECT/GET_ALL_TABLE_PROJECT';
export const GET_SINGLE_PROJECT = 'GET_SINGLE_PROJECT';
export const UPDATE_PROJECT = 'UPDATE_PROJECT';

export const tableSortColumn = (tableId, columnId) => ({
  type: TABLE_SORT_COLUMN,
  payload: { tableId, columnId },
});

export const tableNextPage = (tableId) => ({
  type: TABLE_NEXT_PAGE,
  payload: { tableId },
});

export const tablePageTotalCount = (tableId) => ({
  type: TABLE_PAGE_TOTAL_COUNT,
  payload: { tableId },
});

export const tablePageCount = (tableId) => ({
  type: TABLE_PAGE_COUNT,
  payload: { tableId },
});

export const startCreatingProject = () => ({
  type: CREATE_PROJECT_START,
  payload: {},
});

export const createProject = (data) => async (dispatch) => {
  dispatch(startCreatingProject());
  const {
    accountLead: accountLeadId,
    agent: agentId,
    country: countryId,
    customer,
    endDate,
    engagementCategory: categoryId,
    engagementModel: modelId,
    name,
    startDate,
    projectManager: projectManagerId,
    teamLead: teamLeadId,
  } = data;
  const body = {
    name: name.trim(),
    startDate,
    customerId: customer?.value,
    categoryId,
    modelId,
    countryId,
    accountLeadId,
    endDate,
    agentId,
    projectManagerId,
    teamLeadId,
  };

  const newProjectData = await projectApi.create(body);
  return dispatch({
    type: CREATE_PROJECT,
    payload: newProjectData.data,
  });
};

export const getAllProjects = (params) => async (dispatch) => {
  const data = await projectApi.listAll(params);
  return dispatch({
    type: GET_ALL_PROJECT,
    payload: data,
  });
};

export const getSingleProject = (id) => async (dispatch) => {
  const data = await projectApi.getByName(id);
  return dispatch({
    type: GET_SINGLE_PROJECT,
    payload: data,
  });
};

export const updateProject = (id, data) => async (dispatch) => {
  const res = await projectApi.update(id, data);
  return dispatch({
    type: UPDATE_PROJECT,
    payload: res,
  });
};

export default {
  createProject,
  getAllProjects,
  updateProject,
};
