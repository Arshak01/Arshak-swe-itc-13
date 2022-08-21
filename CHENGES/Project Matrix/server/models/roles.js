'use strict';

module.exports = (sequelize, DataTypes) => {
  const roles = sequelize.define(
    'roles',
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

  roles.associate = function (models) {
    roles.hasMany(models.employee_allocations, {
      foreignKey: {
        name: 'role_id',
        field: 'id',
        allowNull: false,
      },
      onUpdate: 'CASCADE',
      onDelete: 'CASCADE',
    });
  };

  return roles;
};
