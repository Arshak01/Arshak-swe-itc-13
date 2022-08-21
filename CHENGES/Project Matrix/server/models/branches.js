'use strict';

module.exports = (sequelize, DataTypes) => {
  const branches = sequelize.define(
    'branches',
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

  branches.associate = function (db) {
    branches.hasMany(db.employees, {
      foreignKey: {
        name: 'branch_id',
        field: 'id',
      },
      onDelete: 'CASCADE',
      onUpdate: 'CASCADE',
    });
  };

  return branches;
};
