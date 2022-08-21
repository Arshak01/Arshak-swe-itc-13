import styled from 'styled-components';
import { Input } from 'antd';
import CountryPhoneInput from 'antd-country-phone-input';

export const PhoneInput = styled(CountryPhoneInput)`
  border: 1px solid rgba(0, 0, 0, 0.2);
`;

export const InputField = styled(Input)`
  width: 100%;
  height: 48px;
  border-radius: 4px;
`;
