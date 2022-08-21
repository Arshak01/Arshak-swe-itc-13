const host = '127.0.0.1'
const port = 3000
var bodyParser = require('body-parser');
const express = require('express');
const app = express();
const fs = require('fs');

app.use(bodyParser.json())
app.use(bodyParser.raw({ type: 'application/vnd.custom-type' }))
app.use(bodyParser.text({ type: 'text/html' }))

app.route('/users')
    .get((req, res) => {
        let data = fs.readFileSync("data.json");
        res.send(JSON.parse(data));
    })

    .post((req, res) => {
        let data = fs.readFileSync("data.json");
        let myObject = JSON.parse(data);
        let item = {};
        item.id = req.body.id;
        item.name = req.body.name;
        const finalResult = myObject.users;
        finalResult.push(item);
        let newMyObject = {"users" : finalResult}
        fs.writeFileSync("data.json",JSON.stringify(newMyObject));
        res.send(newMyObject);
    })

app.route('/put/:id')
    .put((req, res) => {
        let data = fs.readFileSync("data.json");
        let myObject = JSON.parse(data);
        myObject.users.find((item) => item.id  == id).name = req.body.name;
        fs.writeFileSync("data.json",JSON.stringify(myObject));
        res.send(myObject);
    })

app.route('/delete/:id')
    .delete((req, res) => {
        let data = fs.readFileSync("data.json");
        let myObject = JSON.parse(data);
        const item = myObject.users.filter((item) => item.id  != req.params.id);
        let newMyObject = {"users" : item}
        fs.writeFileSync("data.json",JSON.stringify(newMyObject));
        res.send(newMyObject);
    })

app.listen(port, host, () =>{
    console.log(`Listening at http://${host}:${port}`)
})
