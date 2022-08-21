'use strict';

module.exports = (sequelize, DataTypes) => {
  const requested_resources = sequelize.define(
    'requested_resources',
    {
      id: {
        allowNull: false,
        autoIncrement: true,
        primaryKey: true,
        type: DataTypes.INTEGER,
      },
      name: {
        type: DataTypes.STRING(50),
        allowNull: false,
      },
    },
    {
      createdAt: false,
      updatedAt: false,
    },
  );

  requested_resources.associate = function (db) {
    requested_resources.hasMany(db.project_needs, {
      foreignKey: {
        name: 'resource_id',
        field: 'id',
        allowNull: false,
      },
      onUpdate: 'CASCADE',
      onDelete: 'CASCADE',
    });
  };

  return requested_resources;
};
