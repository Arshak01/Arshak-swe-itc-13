import styled from 'styled-components';

const Footer = styled.div`
  display: flex;
  float: right;
  height: 50px;
  width: calc(100vw - ${({ collapsed }) => (collapsed ? 80 : 200)}px);
  transition: width 0.2s;
  justify-content: center;
  align-items: center;
  padding: 10px 30px 10px 30px;
  box-shadow: 4px 4px 4px 4px rgba(0, 0, 0, 0.1);

  @media (min-width: 300px) and (max-width: 600px) {
    font-size: 10px;
    word-wrap: break-word;
  },
`;

export default Footer;
