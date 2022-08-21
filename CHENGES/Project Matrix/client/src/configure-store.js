import { createLogger } from 'redux-logger';
import { applyMiddleware, compose, createStore } from 'redux';
import thunk from 'redux-thunk';
import rootReducer from './reducers/index-reducer';
const enableLogger = true; // TODO: process?.env?.NODE_ENV !== 'production' // disable for prod

function configureStore(options) {
  const { initialState, history } = options;
  const middleware = [
    thunk,
    // TODO - add more middlewares like errorsMiddleware
  ];

  // Logger must be the last middleware in chain.
  if (enableLogger) {
    const logger = createLogger({
      collapsed: true,
      // Convert immutable to JSON.
      stateTransformer: (state) => JSON.parse(JSON.stringify(state)),
    });
    middleware.push(logger);
  }

  const enhancers = [applyMiddleware(...middleware)];

  // If Redux DevTools Extension is installed use it, otherwise use Redux compose
  /* eslint-disable no-underscore-dangle */
  const composeEnhancers =
    enableLogger && window.__REDUX_DEVTOOLS_EXTENSION_COMPOSE__
      ? window.__REDUX_DEVTOOLS_EXTENSION_COMPOSE__({})
      : compose;
  /* eslint-enable */

  const reduced = rootReducer(history);
  const store = createStore(
    reduced,
    initialState,
    composeEnhancers(...enhancers),
  );
  return store;
}

const SingletonStore = (() => {
  let storeInstance;

  return {
    getInstance: (options) => {
      if (!storeInstance) {
        storeInstance = configureStore(options);
      }
      return storeInstance;
    },
  };
})();

export default SingletonStore;
