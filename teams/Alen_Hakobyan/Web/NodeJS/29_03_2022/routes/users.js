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
  .post(usersControllers.createUser)
  .get(usersControllers.getUsers);

module.exports = router;
