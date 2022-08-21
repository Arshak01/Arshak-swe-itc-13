import {
  CREATE_PROJECT,
  CREATE_PROJECT_START,
  GET_ALL_PROJECT, // TODO: action names are draft
  GET_SINGLE_PROJECT,
  TABLE_NEXT_PAGE,
  TABLE_SORT_COLUMN,
} from '../actions/active-projects-actions';

export const initialState = {
  projects: {
    items: [],
    page: 0,
    totalItems: 0,
    totalPages: 0,
    filter: {},
    isCreating: false,
    form: {
      data: {
        about: '',
        achievements_report: false,
        agent_id: 0,
        budget: '',
        category_id: 0,
        confidential_type: null,
        confidential_type_id: 0,
        country_id: 0,
        customer_id: 0,
        end_date: '',
        id: 0,
        is_active: false,
        is_billable: false,
        logo_url: '',
        model_id: 0,
        name: '',
        startDate: null,
        technology_tools: '',
        customer: {
          about: '',
          address: '',
          contact_phone: { short: 'US' },
          email: '',
          id: 0,
          name: '',
        },
        employee_allocations: [],
      },
    },
  },
};

export default function activeProjectReducer(
  state = initialState,
  { type, payload },
) {
  switch (type) {
    case TABLE_SORT_COLUMN:
      return {
        ...state,
        filter: { sortBy: payload.columnId },
      };
    case TABLE_NEXT_PAGE:
      return {
        ...state,
        page: state.page + 1,
      };
    case CREATE_PROJECT:
      return {
        ...state,
        isCreating: false,
        items: { ...state.items, [payload.projectId]: { ...payload } },
      };
    case CREATE_PROJECT_START:
      return {
        ...state,
        isCreating: true,
      };
    case GET_ALL_PROJECT:
      /* eslint-disable no-case-declarations */
      const { items, totalItems, totalPages, currentPage } = payload;
      /* eslint-disable no-case-declarations */
      const newItems = items.reduce((acc, item) => {
        acc[item.projectId] = item;
        return acc;
      }, {});
      return {
        ...state,
        items: { ...state.items, ...newItems },
        page: currentPage,
        totalItems: totalItems,
        totalPages: totalPages,
        filter: payload.params,
      };
    case GET_SINGLE_PROJECT:
      return {
        ...state,
        form: {
          ...state.form,
          data: payload,
        },
      };
    default:
      return state;
  }
}
