const express = require('express');
const confidentialTypesController = require('../controllers/confidential_types');

const router = express.Router();

router
  .route('/')
  .get(confidentialTypesController.getConfidentialTypes)

module.exports = router;
