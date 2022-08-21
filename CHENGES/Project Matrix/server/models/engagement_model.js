'use strict';

module.exports = (sequelize, DataTypes) => {
  const engagement_model = sequelize.define(
    'engagement_model',
    {
      id: {
        allowNull: false,
        autoIncrement: true,
        primaryKey: true,
        type: DataTypes.INTEGER,
      },
      name: {
        type: DataTypes.STRING(25),
        allowNull: false,
      },
    },
    {
      createdAt: false,
      updatedAt: false,
    },
  );

  engagement_model.associate = function (db) {
    engagement_model.hasMany(db.projects, {
      foreignKey: {
        name: 'model_id',
        field: 'id',
        allowNull: false,
      },
      onUpdate: 'CASCADE',
      onDelete: 'CASCADE',
    });
  };

  return engagement_model;
};
