const jwt = require("jsonwebtoken");

const generateToken = payload => {
  const access_token = jwt.sign(payload, "JWT_ACCESS_TOKEN_SECRET", {
    expiresIn: "10m",
  });
  return access_token;
};

module.exports = {
  generateToken
}
