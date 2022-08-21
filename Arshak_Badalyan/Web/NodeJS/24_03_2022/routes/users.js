const usersControllers = require('../controllers/users');

const express = require('express');
const router = express.Router();

router.route('/:id')
    .get(usersControllers.getUserById)
    .put(usersControllers.updateUser)
    .delete(usersControllers.deleteUser)

router.route('/')
    .get(usersControllers.getAllUsers)
    .post(usersControllers.createUser)

module.exports = router;