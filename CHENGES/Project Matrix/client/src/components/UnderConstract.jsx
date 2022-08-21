import React from 'react';
import { useIntl } from 'react-intl';
import locale from './locale';
import {
  UnderConstractComponent,
  UnderConstractContainer,
  UnderConstractDescription,
  UnderConstractH1,
  UnderConstractImg,
} from '../Styled';

const UnderConstract = () => {
  const { formatMessage } = useIntl();

  return (
    <UnderConstractComponent>
      <UnderConstractContainer>
        <UnderConstractH1>
          {formatMessage(locale.underConstructTitle)}
        </UnderConstractH1>
        <UnderConstractImg />
        <UnderConstractDescription>
          {formatMessage(locale.underConstructContent)}
        </UnderConstractDescription>
      </UnderConstractContainer>
    </UnderConstractComponent>
  );
};

export default UnderConstract;
