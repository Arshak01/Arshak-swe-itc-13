const express = require("express");

const usersControllers = require("../controllers/users");

const router = express.Router();

router
  .route("/:id")
  .get(usersControllers.getUserById)
  .put(usersControllers.updateUserById)
  .delete(usersControllers.deleteUserById);

router
  .route("/")
  .get(usersControllers.auth,usersControllers.getUsers)
  .post(usersControllers.createUser);

router
  .route("/login/:Name/:Password")
  .get(usersControllers.login);

module.exports = router;
