import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';
import reportWebVitals from './reportWebVitals';
import {
  ApolloClient,
  InMemoryCache,
  ApolloProvider,
  useQuery,
  gql
} from "@apollo/client";

const client = new ApolloClient({
  uri: 'http://localhost:4000/graphql',
  cache: new InMemoryCache()
});

const GET_ALL_USERS = gql`
  query Query {
    user {
      id
      Name
      SurName
      Email
      Password
    }
  }
`;

function FindAllUsers() {
  const { loading, error, data } = useQuery(GET_ALL_USERS);

  if (loading) return <p>Loading...</p>;
  if (error) return <p>Error :(</p>;

  return data.user.map(({ id, Name, SurName, Email, Password }) => (
    <div key={id}>
      <ul>
        <p>Id : {id}</p>
        <p>Name : {Name}</p>
        <p>SurName : {SurName}</p>
        <p>Email : {Email}</p>
        <p>Password : {Password}</p>
      </ul>
    </div>
  ));
}

ReactDOM.render(
  <React.StrictMode>
    <ApolloProvider client={client}>
      <FindAllUsers />
    </ApolloProvider>,
  </React.StrictMode>,
  document.getElementById('root')
);


reportWebVitals();