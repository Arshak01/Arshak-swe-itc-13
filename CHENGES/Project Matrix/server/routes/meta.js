const express = require('express');
const metaControllers = require('../controllers/meta');

const router = express.Router();

router.route('/').get(metaControllers.listAll);

module.exports = router;
