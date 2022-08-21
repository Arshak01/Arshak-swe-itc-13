const { ApolloServerPluginDrainHttpServer } = require('apollo-server-core');
const { ApolloServer } = require('apollo-server-express');
const { typeDefs } = require('./schema/schema');
const { resolvers } = require('./resolvers/resolvers');
const User = require('./models/index');
const express = require('express');
const http = require('http');


async function startApolloServer(typeDefs, resolvers) {
  const app = express();
  const httpServer = http.createServer(app);

  const server = new ApolloServer({
    typeDefs,
    resolvers,
    plugins: [ApolloServerPluginDrainHttpServer({ httpServer })],
  });

  await server.start();

  server.applyMiddleware({ app });

  await new Promise(resolve => httpServer.listen({ port: 4000 }, resolve));

  console.log(`🚀 Server ready at http://localhost:4000${server.graphqlPath}`);
}


User.sequelize
    .sync()
    .then(() => {
        startApolloServer(typeDefs,resolvers);
    })
    .catch((error) => {
        console.log(`Unable connect to the server ${error} `)
    })
