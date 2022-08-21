'use strict';

module.exports = (sequelize, DataTypes) => {
  const project_needs = sequelize.define(
    'project_needs',
    {
      id: {
        allowNull: false,
        autoIncrement: true,
        primaryKey: true,
        type: DataTypes.INTEGER,
      },
      amount: {
        type: DataTypes.INTEGER,
        allowNull: true,
      },
      start_date: {
        type: DataTypes.DATE,
        allowNull: false,
      },
      end_date: {
        type: DataTypes.DATE,
        allowNull: true,
      },
      link: {
        type: DataTypes.STRING(50),
        allowNull: true,
      },
      employee_count_change: {
        type: DataTypes.INTEGER,
        allowNull: false,
      },
      project_id: {
        type: DataTypes.INTEGER,
        allowNull: false,
      },
      resource_id: {
        type: DataTypes.INTEGER,
        allowNull: true,
      },
      unit_id: {
        type: DataTypes.INTEGER,
        allowNull: false,
      },
    },
    {},
  );

  project_needs.associate = function (db) {
    project_needs.belongsTo(db.projects, {
      foreignKey: {
        name: 'project_id',
        field: 'project_id',
        allowNull: false,
      },
      onDelete: 'CASCADE',
      onUpdate: 'CASCADE',
    });
  };

  project_needs.associate = function (db) {
    project_needs.belongsTo(db.units, {
      foreignKey: {
        name: 'unit_id',
        field: 'unit_id',
        allowNull: false,
      },
      onDelete: 'CASCADE',
      onUpdate: 'CASCADE',
    });
  };

  project_needs.associate = function (db) {
    project_needs.belongsTo(db.requested_resources, {
      foreignKey: {
        name: 'resource_id',
        field: 'resource_id',
        allowNull: false,
      },
      onDelete: 'CASCADE',
      onUpdate: 'CASCADE',
    });
  };

  return project_needs;
};
