const db = require("./models/index");
const cors = require("cors");
const express = require("express");
const bodyParser = require("body-parser");

const routes = require("./routes/index");

const app = express();
const port = 3000;

app.use(cors());
app.use(bodyParser.json());
app.use(routes);

db.sequelize
  .sync()
  .then(() => {
    app.listen(port, () => {
      console.log(`Example app listening on port ${port}`);
    });
  })
  .catch((error) => {
    console.error("Unable to connect to the database:", error);
  });
