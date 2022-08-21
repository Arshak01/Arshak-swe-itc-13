'use strict';

module.exports = (sequelize, DataTypes) => {
  const positions = sequelize.define(
    'positions',
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
      min_rate: {
        type: DataTypes.FLOAT(3),
        allowNull: false,
      },
      min_experiance: {
        type: DataTypes.FLOAT(3),
        allowNull: false,
      },
    },
    {
      createdAt: false,
      updatedAt: false,
    },
  );

  positions.associate = function (db) {
    positions.hasMany(db.employees, {
      foreignKey: {
        name: 'position_id',
        field: 'id',
      },
      onDelete: 'CASCADE',
      onUpdate: 'CASCADE',
    });
  };

  return positions;
};
