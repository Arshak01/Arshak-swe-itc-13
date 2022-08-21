const express = require("express");

const usersControllers = require("../controllers/users");

const router = express.Router();

router
  .route("/")
  .post(usersControllers.createUser)
  .get(usersControllers.auth,usersControllers.getUsers)

  router
  .route("/login")
  .post(usersControllers.login)

router
  .route("/:id")
  .get(usersControllers.getUserById)
  .put(usersControllers.updateUserById)
  .delete(usersControllers.deleteUserById);

module.exports = router;
