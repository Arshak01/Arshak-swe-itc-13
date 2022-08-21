const express = require("express");
const app = express();
const port = 3000;
const fs = require("fs");
const bodyParser = require("body-parser");
app.use(bodyParser.json());

app
  .route("/users")
  .get((req, res) => {
    fs.readFile("./users.json", "utf8", (error, data) => {
      const users = JSON.parse(data);
      if (error) {
        res.status = 500;
        res.send(err).end();
      } else {
        res.send(JSON.stringify(users));
      }
    });
  })
  .post((req, res) => {
    fs.readFile("./users.json", "utf8", (error, data) => {
      if (error) {
        res.status = 500;
        res.send(err).end();
      } else {
        const newUser = JSON.parse(data);
        newUser.push(req.body);
        fs.writeFile("./users.json", JSON.stringify(newUser), (err) => {
          if (err) {
            console.log("Error");
          }
        });
      }
    });
  });

app
  .route("/users/:id")
  .put((req, res) => {
    fs.readFile("./users.json", "utf8", (error, data) => {
      if (error) {
        res.status = 500;
        res.send(err).end();
      } else {
        const users = JSON.parse(data);
        users[users.findIndex((user) => user.id == req.params.id)].name =
          req.body.name;
        fs.writeFile("./users.json", JSON.stringify(users, null, 2), (err) => {
          if (err) {
            console.log("Error");
          } else {
            res.end("Changed");
          }
        });
      }
    });
  })
  .delete((req, res) => {
    fs.readFile("./users.json", "utf8", (error, data) => {
      if (error) {
        res.status = 500;
        res.send(err).end();
      } else {
        const users = JSON.parse(data);
        const newUsers = users.filter((user) => user.id != req.params.id);
        fs.writeFile(
          "./users.json",
          JSON.stringify(newUsers, null, 2),
          (err) => {
            if (err) {
              console.log("Error");
            } else {
              res.send("Deleted");
            }
          }
        );
      }
    });
  });
app.listen(port, () => {
  console.log(`app listening on port ${port}`);
});
