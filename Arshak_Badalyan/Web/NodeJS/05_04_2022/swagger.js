const swaggerAutogen = require('swagger-autogen')

const options = {
  openapi: '3.0.2',
  autoHeaders: false,
  autoQuery: true,
  autoBody: true
}

const doc = {
  info: {
    version: '3.0.2',
    title: 'Swaggers',
    description: 'This is my swagger tasks',
  },
  host: 'localhost:3000',
  basePath: '/',
  schemes: ['http','https'],
  consumes: ['application/json'],
  produces: ['application/json'],
  tags: [
    {
      name: 'User',
      description: 'Endpoints',
    },
  ],
  securityDefinitions: {
    bearerAuth:{
      type: 'http',
      scheme: 'bearer',
      bearerFormat: 'JWT'
    }
  },
  definitions: {},
  components: {
    CreateUser:{
      type: "object",
      properties: {
        Name: {
          type: "string",
          required: false
        },
        SurName: {
          type: "string",
          required: false
        },
        Email: {
          type: "string",
          required: false
        },
        Password: {
          type: "string",
          required: false
        }
      }
    },
    Login:{
      type: "object",
      properties: {
        Name: {
          type: "string",
          required: false
        },
        Password: {
          type: "string",
          required: false
        }
      }
    },
    UpdateUser:{
      type: "object",
      properties: {
        Name: {
          type: "string",
          required: false
        },
        SurName: {
          type: "string",
          required: false
        },
        Email: {
          type: "string",
          required: false
        }
      }
    }
  }
};



const outputFile = './swagger-output.json';
const endpointsFiles = ['./routes/index.js'];

swaggerAutogen(options)(outputFile, endpointsFiles, doc).then(() => {
    require('./index.js');
});

