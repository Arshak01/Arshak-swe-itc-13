"use strict";
const { Model } = require("sequelize");
module.exports = (sequelize, DataTypes) => {
  class User extends Model {
    static associate(models) {}
  }
  User.init(
    {
      Name: DataTypes.STRING,
      SurName: DataTypes.STRING,
      Email: DataTypes.STRING,
      Password: DataTypes.STRING
    },
    {
      sequelize,
      modelName: "User",
    }
  );
  return User;
};
