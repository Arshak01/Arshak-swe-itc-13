import React, { useEffect, useState } from 'react';
import { useDispatch } from 'react-redux';
import { BrowserRouter } from 'react-router-dom';
import { useIntl } from 'react-intl';
import 'antd/dist/antd.min.css';
import './App.css';
import {
  Container,
  CopyRigthText,
  Logo,
  MainWrapper,
  NotificationButton,
  NotificationIcon,
  Placeholder,
  ContentComponent as Content,
} from './Styled';
import Routes from './routes';
import { useLocale } from './components/LanguageWrapper';
import { SelectLanguage } from './components/SelectLanguage';
import Header from './components/Header';
import Footer from './components/Footer';
import Sidebar from './components/Sidebar';

import { getAllCustomers } from './actions/active-customers-actions';
import { getMeta } from './actions/meta-actions';
import locales from './locale';

const App = () => {
  const { formatMessage } = useIntl();
  const { locale, selectLanguage } = useLocale();
  const dispatch = useDispatch();
  const [collapsed, setCollapsed] = useState(true);

  useEffect(() => {
    dispatch(getAllCustomers());
    dispatch(getMeta());
  }, [dispatch]);

  return (
    <BrowserRouter>
      <Header>
        <Logo to="/" as="img" />
        <Container>
          <NotificationButton>
            <NotificationIcon />
          </NotificationButton>
          <Placeholder />
        </Container>
      </Header>
      <MainWrapper style={{ backgroundColor: '#fafafa' }}>
        <Sidebar setCollapsed={setCollapsed} />
        <Content collapsed={collapsed}>
          <Routes />
        </Content>
      </MainWrapper>
      <Footer collapsed={collapsed}>
        <CopyRigthText>
          {formatMessage(locales.footerDescription)}
        </CopyRigthText>
        <SelectLanguage value={locale} onChange={selectLanguage} />
      </Footer>
    </BrowserRouter>
  );
};

export default App;
