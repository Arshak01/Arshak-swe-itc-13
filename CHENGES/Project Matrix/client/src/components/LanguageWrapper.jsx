import React, { useCallback, useContext, useEffect, useState } from 'react';
import { IntlProvider } from 'react-intl';
import PropTypes from 'prop-types';
import French from '../lang/fr';
import Armenian from '../lang/am';
import English from '../lang/en';
import { CONSTANTS, LOCALE } from '../utils/constants';

const { EN, FR, AM } = LOCALE;
const { LANGUAGE_WRAPPER } = CONSTANTS;
const Context = React.createContext(LANGUAGE_WRAPPER);
export const useLocale = () => useContext(Context);

const LanguageWrapper = (props) => {
  const [locale, setLocale] = useState(EN.code);
  const [messages, setMessages] = useState(English);

  const selectLanguage = useCallback((e) => {
    const newLocale = e.target.value;
    setLocale(newLocale);
  }, []);

  useEffect(() => {
    if (locale === AM.code) {
      setMessages(Armenian);
    } else if (locale === FR.code) {
      setMessages(French);
    } else {
      setMessages(English);
    }
  }, [locale]);

  return (
    <Context.Provider value={{ locale, selectLanguage }}>
      <IntlProvider messages={messages} locale={locale}>
        {props.children}
      </IntlProvider>
    </Context.Provider>
  );
};

LanguageWrapper.propTypes = {
  children: PropTypes.node,
};

export default LanguageWrapper;
