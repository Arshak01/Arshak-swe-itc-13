import { combineReducers } from 'redux';
import activeProjectsReducer from './active-projects-reducer';
import activeCustomersReducer from './active-customers-reducer';
import employeesReducer from './employees-reducer';
import metaReducer from './meta-reducer';

const rootReducer = () =>
  combineReducers({
    projects: activeProjectsReducer,
    customers: activeCustomersReducer,
    employees: employeesReducer,
    meta: metaReducer,
  });

export default rootReducer;
