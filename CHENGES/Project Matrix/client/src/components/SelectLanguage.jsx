import React from 'react';
import { useLocale } from './LanguageWrapper';
import { LOCALE } from '../utils/constants';

export const SelectLanguage = () => {
  const { locale, selectLanguage } = useLocale();
  return (
    <select value={locale} onChange={selectLanguage}>
      {Object.entries(LOCALE).map(([key, value]) => (
        <option key={key} value={value.code}>
          {value.label}
        </option>
      ))}
    </select>
  );
};
