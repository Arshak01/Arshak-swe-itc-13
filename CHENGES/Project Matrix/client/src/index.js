import React from 'react';
import ReactDOM from 'react-dom/client';
import { Provider } from 'react-redux';
import App from './App';
import LanguageWrapper from './components/LanguageWrapper';
import reportWebVitals from './reportWebVitals';
import store from './store';

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
  <Provider store={store}>
    <LanguageWrapper>
      <App />
    </LanguageWrapper>
  </Provider>,
);

reportWebVitals();
