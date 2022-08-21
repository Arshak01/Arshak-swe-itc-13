'use strict';

module.exports = (sequelize, DataTypes) => {
  const statuses = sequelize.define(
    'statuses',
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

  statuses.associate = function (db) {
    statuses.hasMany(db.employees, {
      foreignKey: {
        name: 'status_id',
        field: 'id',
        allowNull: false,
      },
      onUpdate: 'CASCADE',
      onDelete: 'CASCADE',
    });
  };

  return statuses;
};
