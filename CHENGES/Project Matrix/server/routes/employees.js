const express = require('express');
const employeeControllers = require('../controllers/employees');

const router = express.Router();

router
  .route('/')
  .get(employeeControllers.getAllEmployees)
  .post(employeeControllers.addEmployee)
  .put(employeeControllers.updateEmployee)
  .delete(employeeControllers.deleteEmployee);

module.exports = router;
