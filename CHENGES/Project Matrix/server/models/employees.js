'use strict';

module.exports = (sequelize, DataTypes) => {
  const employees = sequelize.define(
    'employees',
    {
      id: {
        allowNull: false,
        autoIncrement: true,
        primaryKey: true,
        type: DataTypes.INTEGER,
      },
      planned_rate: {
        type: DataTypes.FLOAT(3),
        allowNull: false,
      },
      actual_rate: {
        type: DataTypes.FLOAT(3),
        allowNull: false,
      },
      month: {
        type: DataTypes.DATE,
        allowNull: false,
      },
      branch_id: {
        type: DataTypes.INTEGER,
        allowNull: false,
      },
      unit_id: {
        type: DataTypes.INTEGER,
        allowNull: false,
      },
      position_id: {
        type: DataTypes.INTEGER,
        allowNull: false,
      },
      status_id: {
        type: DataTypes.INTEGER,
        allowNull: false,
      },
      hr_employee_id: {
        type: DataTypes.INTEGER,
        allowNull: false,
      },
    },
    {
      createdAt: false,
      updatedAt: false,
    },
  );

  employees.associate = function (models) {
    employees.belongsTo(models.hr_employee, {
      foreignKey: {
        name: 'hr_employee_id',
        field: 'hr_employee_id',
      },
      onDelete: 'CASCADE',
      onUpdate: 'CASCADE',
    });
    employees.belongsTo(models.statuses, {
      foreignKey: {
        name: 'status_id',
        field: 'status_id',
      },
      onDelete: 'CASCADE',
      onUpdate: 'CASCADE',
    });
    employees.hasMany(models.daily_saved_employee_history, {
      foreignKey: {
        name: 'employee_id',
        field: 'id',
      },
      onDelete: 'CASCADE',
      onUpdate: 'CASCADE',
    });
    employees.hasMany(models.monthly_saved_employee_history, {
      foreignKey: {
        name: 'employee_id',
        field: 'id',
      },
      onDelete: 'CASCADE',
      onUpdate: 'CASCADE',
    });
    employees.belongsTo(models.units, {
      foreignKey: {
        name: 'unit_id',
        field: 'unit_id',
      },
      onDelete: 'CASCADE',
      onUpdate: 'CASCADE',
    });
    employees.hasMany(models.employee_allocations, {
      foreignKey: {
        name: 'employee_id',
        field: 'id',
      },
      onDelete: 'CASCADE',
      onUpdate: 'CASCADE',
    });
    employees.belongsTo(models.positions, {
      foreignKey: {
        name: 'position_id',
        field: 'position_id',
      },
      onDelete: 'CASCADE',
      onUpdate: 'CASCADE',
    });
    employees.belongsTo(models.branches, {
      foreignKey: {
        name: 'branch_id',
        field: 'branch_id',
      },
      onDelete: 'CASCADE',
      onUpdate: 'CASCADE',
    });
  };

  return employees;
};
