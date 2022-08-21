const express = require('express');
const cors = require('cors');
const bodyParser = require('body-parser');
const db = require('./models/index');
const logger = require('./utils/logger');
const router = require('./routes/index');
require('dotenv').config();

const PORT = process.env.PORT;
const HOST = process.env.HOST;
const app = express();

app.use(cors());
app.use(bodyParser.json());
app.use('/api/v1', router);

app.get('/ping', (req, res) => {
  res.send('Pong');
});

db.sequelize
  .sync()
  .then(() => {
    app.listen(PORT, () => {
      logger.info(`App listening on http://${HOST}:${PORT}`);
    });
  })
  .catch((error) => {
    logger.error(`Unable to connect to the database: ${error}`);
  });
