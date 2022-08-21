'use strict';

module.exports = (sequelize, DataTypes) => {
  const units = sequelize.define(
    'units',
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

  units.associate = function (db) {
    units.hasMany(db.employees, {
      foreignKey: {
        name: 'unit_id',
        field: 'id',
        allowNull: false,
      },
      onUpdate: 'CASCADE',
      onDelete: 'CASCADE',
    });
  };

  units.associate = function (db) {
    units.hasMany(db.project_needs, {
      foreignKey: {
        name: 'unit_id',
        field: 'id',
        allowNull: false,
      },
      onUpdate: 'CASCADE',
      onDelete: 'CASCADE',
    });
  };

  return units;
};
