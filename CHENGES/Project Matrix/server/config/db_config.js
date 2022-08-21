require('dotenv').config();

module.exports = {
  HOST: process.env.HOST,
  USER: process.env.PSQL_USER,
  PASSWORD: process.env.PSQL_PASSWORD,
  DB: process.env.PSQL_DB,
  dialect: 'postgres',
};
