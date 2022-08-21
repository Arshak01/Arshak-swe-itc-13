const routes = require('./routes/index.js');
const bodyParser = require('body-parser');
const port = 3000
const express = require('express');
const app = express();

app.use(bodyParser.json());
app.use(routes);

app.listen(port, () =>{
    console.log(`Listening :${port}`)
})