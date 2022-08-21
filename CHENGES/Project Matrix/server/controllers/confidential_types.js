const { confidential_types, } = require('../models/index');

const getConfidentialTypes = async (req, res) => {
  try {
    const data = await confidential_types.findAll(); // TODO: pagination?
    res.send(data);
  } catch (error) {
    res.status(500).send(error); // TODO
  }
};

module.exports = {
  getConfidentialTypes
};
