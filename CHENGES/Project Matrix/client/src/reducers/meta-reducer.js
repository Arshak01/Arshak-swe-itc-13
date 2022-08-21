import { GET_META_INFO } from '../actions/meta-actions';

export const initialState = {
  countries: [],
  engagementModels: [],
  engagementCategories: [],
  agents: [],
  teamLead: [],
  projectManager: [],
};

export default function metaReducer(state = initialState, { type, payload }) {
  switch (type) {
    case GET_META_INFO:
      /* eslint-disable no-case-declarations */
      const {
        countries,
        engagement_models: engagementModels,
        engagement_categories: engagementCategories,
        agents,
        teamLead,
        projectManager,
      } = payload;
      return {
        ...state,
        countries,
        engagementModels,
        engagementCategories,
        agents,
        teamLead,
        projectManager,
      };
    default:
      return state;
  }
}
