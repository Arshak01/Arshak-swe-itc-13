const express = require('express');
const customerControllers = require('../controllers/customers');

const router = express.Router();

router
  .route('/')
  .get(customerControllers.getAllCustomers)
  .post(customerControllers.addCustomer);

router
  .route('/:customerId')
  .put(customerControllers.updateCustomer)
  .delete(customerControllers.deleteCustomer);

module.exports = router;
