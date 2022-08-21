const jwt = require('jsonwebtoken');
const constants = require('../utils/constants');

const auth = (req, res, next) => {
  try {
    const { authorization } = req.headers;
    if (!authorization) throw { errorMessage: 'Unauthorized' };

    const token = authorization.split(' ')[1];
    if (!token) throw { errorMessage: 'Invalid token' };

    const decodedToken = jwt.verify(token, constants.TOKEN_SECRET);

    const userId = decodedToken.userId;
    if (req.body?.userId && req.body.userId !== userId) {
      throw { errorMessage: 'Invalid user ID' };
    }
    next();
  } catch (error) {
    if (error.errorMessage === 'Unauthorized')
      res.status(401).send('Authorization error');

    if (error.errorMessage === 'Invalid token')
      res.status(401).send('Your token is not valid');

    if (error.errorMessage === 'Invalid user ID')
      res.status(404).send('Invalid user ID');

    res.status(400).send('Something went wrong');
  }
};

module.exports = { auth };
