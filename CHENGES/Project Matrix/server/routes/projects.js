const express = require('express');
const projectControllers = require('../controllers/projects');
const nameCheckController = require('../controllers/checkProjectName');
const authMiddleware = require('../middlewares/auth');

const router = express.Router();

router
  .route('/')
  .get(authMiddleware.auth, projectControllers.getAllProjects)
  .post(projectControllers.addProject);

router.route('/checkProjectName').get(nameCheckController.isAvailable);

router.route('/:projectId/uploadLogo').post(projectControllers.uploadLogo);

router
  .route('/:projectId')
  .get(authMiddleware.auth, projectControllers.getProjectByName)
  .put(projectControllers.updateProject)
  .delete(projectControllers.deleteProject);

module.exports = router;
