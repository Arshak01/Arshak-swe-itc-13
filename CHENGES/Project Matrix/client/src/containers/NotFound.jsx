import React from 'react';
import { useIntl } from 'react-intl';
import locale from './locale';
import {
  NotFoundComponent,
  NotFoundContainerBox,
  NotFoundDescription,
  NotFoundH1,
  NotFoundH3,
  NotFoundImg,
} from '../Styled';
import { NOT_FOUND_AND_UNDER_CONSTRACT } from '../utils/constants';

const NotFound = () => {
  const { formatMessage } = useIntl();

  return (
    <NotFoundComponent>
      <NotFoundImg>
        <NotFoundH1>{NOT_FOUND_AND_UNDER_CONSTRACT.ERROR}</NotFoundH1>
      </NotFoundImg>
      <NotFoundContainerBox>
        <NotFoundH3> {formatMessage(locale.notfoundTitle)}</NotFoundH3>
        <NotFoundDescription>
          {formatMessage(locale.notfoundContent)}
        </NotFoundDescription>
      </NotFoundContainerBox>
    </NotFoundComponent>
  );
};

export default NotFound;
