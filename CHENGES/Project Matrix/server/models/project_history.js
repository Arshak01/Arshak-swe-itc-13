'use strict';

module.exports = (sequelize, DataTypes) => {
  const project_history = sequelize.define(
    'project_history',
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
      updated_confidential_type: {
        type: DataTypes.STRING(25),
        allowNull: false,
      },
      updated_category: {
        type: DataTypes.STRING(25),
        allowNull: false,
      },
      updated_model: {
        type: DataTypes.STRING(25),
        allowNull: false,
      },
      updated_activity: {
        type: DataTypes.BOOLEAN,
        allowNull: false,
      },
      updated_budget: {
        type: DataTypes.STRING(25),
        allowNull: true,
      },
    },
    {},
  );

  project_history.associate = function (db) {
    project_history.belongsTo(db.projects, {
      foreignKey: {
        name: 'project_id',
        field: 'id',
      },
      onDelete: 'CASCADE',
      onUpdate: 'CASCADE',
    });
  };

  return project_history;
};
