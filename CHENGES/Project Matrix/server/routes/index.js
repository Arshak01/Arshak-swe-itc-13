const express = require('express');
const projects = require('./projects');
const customers = require('./customers');
const employees = require('./employees');
const meta = require('./meta');
const confidentialTypes = require('./confidential_types');

const router = express.Router();

router.use('/projects', projects);
router.use('/customers', customers);
router.use('/employees', employees);
router.use('/meta', meta);
router.use('/confidential_types', confidentialTypes);

module.exports = router;
