'use strict';

module.exports = (sequelize, DataTypes) => {
  const employee_allocations = sequelize.define(
    'employee_allocations',
    {
      id: {
        allowNull: false,
        autoIncrement: true,
        primaryKey: true,
        type: DataTypes.INTEGER,
      },
      start_date: {
        type: DataTypes.DATE,
        allowNull: false,
      },
      end_date: {
        type: DataTypes.DATE,
        allowNull: true,
      },
      rate: {
        type: DataTypes.FLOAT(3),
        allowNull: false,
      },
      role_id: {
        type: DataTypes.INTEGER,
        allowNull: false,
      },
      project_id: {
        type: DataTypes.INTEGER,
        allowNull: false,
      },
      employee_id: {
        type: DataTypes.INTEGER,
        allowNull: false,
      },
    },
    {
      createdAt: false,
      updatedAt: false,
    },
  );

  employee_allocations.associate = function (models) {
    employee_allocations.belongsTo(models.projects, {
      foreignKey: {
        name: 'project_id',
        field: 'project_id',
        allowNull: false,
      },
      onDelete: 'CASCADE',
      onUpdate: 'CASCADE',
    });
    employee_allocations.belongsTo(models.employees, {
      foreignKey: {
        name: 'employee_id',
        field: 'employee_id',
        allowNull: false,
      },
      onDelete: 'CASCADE',
      onUpdate: 'CASCADE',
    });
    employee_allocations.belongsTo(models.roles, {
      foreignKey: {
        name: 'role_id',
        field: 'role_id',
      },
      onDelete: 'CASCADE',
      onUpdate: 'CASCADE',
    });
  };

  return employee_allocations;
};
