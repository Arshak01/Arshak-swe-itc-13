const { projects, Sequelize } = require('../models/index');

const isAvailable = async (req, res) => {
  /*
    #swagger.tags = ["check_project_name"]
    #swagger.summary = "Check project name"
    #swagger.description = "Checking is the project name available"
    #swagger.operationId = "checkName"
  */
  try {
    const project = await projects.findOne({
      where: {
        name: Sequelize.where(
          Sequelize.fn('LOWER', Sequelize.col('name')),
          'LIKE',
          `${req.query.name}`,
        ),
      },
    });
    res.send({ isAvailable: !project });
  } catch (error) {
    res.status(500).send('Internal Server Error');
  }
};

module.exports = { isAvailable };
