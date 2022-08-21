'use strict';

module.exports = (sequelize, DataTypes) => {
  const daily_saved_employee_history = sequelize.define(
    'daily_saved_employee_history',
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
      updated_status: {
        type: DataTypes.STRING(25),
        allowNull: false,
      },
      updated_rate: {
        type: DataTypes.FLOAT(3),
        allowNull: false,
      },
      employee_id: {
        type: DataTypes.INTEGER,
        allowNull: false,
      },
    },
    {},
  );

  daily_saved_employee_history.associate = function (db) {
    daily_saved_employee_history.belongsTo(db.employees, {
      foreignKey: {
        name: 'employee_id',
        field: 'employee_id',
      },
      onDelete: 'CASCADE',
      onUpdate: 'CASCADE',
    });
  };

  return daily_saved_employee_history;
};
