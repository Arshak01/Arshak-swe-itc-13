import SingletonStore from './configure-store';
import { initialState } from './reducers/active-projects-reducer';

const store = SingletonStore.getInstance({ initialState });

export default store;
