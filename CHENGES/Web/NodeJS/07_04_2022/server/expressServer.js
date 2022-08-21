const express = require('express');
const { graphqlHTTP } = require('express-graphql');
const { buildSchema } = require('graphql');
const {User} = require("./models/index")


const getUsers = async() =>{
  const user = await User.findAll({});
  return  user
}

const schema = buildSchema(`
  type User {
    Name : String
    SurName : String
    Email : String
    Password : String
  }
  type Query {
    getAllUsers : [User]
  }

`);

const root = { getAllUsers: getUsers()};

const app = express();

app.use('/graphql', graphqlHTTP({
  schema: schema,
  rootValue: root,
  graphiql: true,
}));

app.listen(4000, () => console.log('Now browse to localhost:4000/graphql'));