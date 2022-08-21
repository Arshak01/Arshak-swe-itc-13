import { GET_EMPLOYEES_INFO } from '../actions/employees-actions';

export const initialState = {
  account_lead: {},
  project_manager: {},
  team_lead: {},
  all: {},
};

export default function employeesReducer(
  state = initialState,
  { type, payload },
) {
  switch (type) {
    case GET_EMPLOYEES_INFO:
      /* eslint-disable no-case-declarations */
      const { data, params } = payload;
      const newItems = data.reduce((acc, item) => {
        acc[item.id] = item;
        return acc;
      }, {});
      const { position = 'all' } = params;
      return {
        ...state,
        [position]: { ...state?.[position], ...newItems },
      };
    default:
      return state;
  }
}
