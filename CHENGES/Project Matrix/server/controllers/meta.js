const {
  agents,
  countries,
  engagement_category,
  engagement_model,
} = require('../models');

const logger = require('../utils/logger');

const listAll = async (_, res) => {
  /*
    #swagger.tags = ['meta']
    #swagger.summary = 'Get all meta available'
    #swagger.description = 'Get Meta for definitions'
    #swagger.operationId = 'listAll'
  */
  try {
    logger.debug('get meta');
    const countriesData = await countries.findAll();
    const modelData = await engagement_model.findAll();
    const categoryData = await engagement_category.findAll();
    const agentData = await agents.findAll();
    res.send({
      countries: countriesData,
      engagement_models: modelData,
      engagement_categories: categoryData,
      agents: agentData,
    });
  } catch (error) {
    logger.debug(error);
    res.status(500).send(error);
  }
};

module.exports = {
  listAll,
};
