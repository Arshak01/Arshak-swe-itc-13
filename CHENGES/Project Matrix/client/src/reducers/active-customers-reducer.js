import {
  ADD_CUSTOMER,
  GET_ALL_AVAILABLE_CUSTOMERS,
} from '../actions/active-customers-actions';

export const initialState = {
  items: [],
  page: 0,
  count: 0,
  totalCount: 0,
  filter: {},
};

export default function activeCustomersReducer(
  state = initialState,
  { type, payload },
) {
  switch (type) {
    case GET_ALL_AVAILABLE_CUSTOMERS:
      /* eslint-disable no-case-declarations */
      const {
        totalItems: totalCount,
        customers,
        currentPage: page = 1,
      } = payload;
      /* eslint-disable no-case-declarations */
      return {
        ...state,
        totalCount,
        page,
        items: customers,
        count: customers.length,
      };
    case ADD_CUSTOMER:
      // eslint-disable-next-line no-case-declarations
      const {
        id,
        address,
        email,
        info: about,
        name,
        phone: contact_phone,
      } = payload;
      return {
        ...state,
        totalCount: state.totalCount + 1,
        count: state.count + 1,
        items: [
          ...state.items,
          {
            id,
            address,
            email,
            about,
            name,
            contact_phone,
          },
        ],
      };
    default:
      return state;
  }
}
