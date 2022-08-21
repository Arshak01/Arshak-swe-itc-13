const swaggerAutogen = require('swagger-autogen');
const packageJson = require('./package.json');
require('dotenv').config();

const options = {
  openapi: '3.0.2',
  autoHeaders: false,
};
const PORT = process.env.PORT;
const HOST = process.env.HOST;

const doc = {
  info: {
    version: packageJson.version,
    title: 'Project Matrix APIs',
    description: 'Describe the structure of all APIs in this app',
  },
  host: `${HOST}:${PORT}`,
  basePath: '/api/v1',
  schemes: ['http', 'https'],
  consumes: ['application/json'],
  produces: ['application/json'],
};

const outputFile = './swagger-output.json';
const endPointsFiles = ['./routes/index.js'];

swaggerAutogen(options)(outputFile, endPointsFiles, doc).then(() => {
  require('./index.js');
});
