'use strict';

module.exports = (sequelize, DataTypes) => {
  const monthly_saved_employee_history = sequelize.define(
    'monthly_saved_employee_history',
    {
      id: {
        allowNull: false,
        autoIncrement: true,
        primaryKey: true,
        type: DataTypes.INTEGER,
      },
      updated_branch: {
        type: DataTypes.STRING(50),
        allowNull: false,
      },
      updated_position: {
        type: DataTypes.STRING(50),
        allowNull: false,
      },
      start_month: {
        type: DataTypes.DATE,
        allowNull: false,
      },
    },
    {},
  );

  monthly_saved_employee_history.associate = function (db) {
    monthly_saved_employee_history.belongsTo(db.employees, {
      foreignKey: {
        name: 'employee_id',
        field: 'id',
      },
      onDelete: 'CASCADE',
      onUpdate: 'CASCADE',
    });
  };

  return monthly_saved_employee_history;
};
