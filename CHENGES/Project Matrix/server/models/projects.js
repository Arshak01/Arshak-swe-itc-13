'use strict';

module.exports = (sequelize, DataTypes) => {
  const projects = sequelize.define(
    'projects',
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
      start_date: {
        type: DataTypes.DATE,
        allowNull: false,
      },
      end_date: {
        type: DataTypes.DATE,
        allowNull: true,
      },
      about: {
        type: DataTypes.STRING(255),
        allowNull: true,
      },
      technology_tools: {
        type: DataTypes.STRING(255),
        allowNull: true,
      },
      budget: {
        type: DataTypes.STRING(25),
        allowNull: true,
      },
      confidential_type_id: {
        type: DataTypes.INTEGER,
        allowNull: true,
      },
      logo_url: {
        type: DataTypes.STRING(25),
        allowNull: true,
      },
      is_active: {
        type: DataTypes.BOOLEAN,
        allowNull: false,
        defaultValue: false,
      },
      achievements_report: {
        type: DataTypes.BOOLEAN,
        allowNull: true,
        defaultValue: false,
      },
      is_billable: {
        type: DataTypes.BOOLEAN,
        allowNull: false,
        defaultValue: false,
      },
      customer_id: {
        type: DataTypes.INTEGER,
        allowNull: false,
      },
      agent_id: {
        type: DataTypes.INTEGER,
        allowNull: true,
      },
      category_id: {
        type: DataTypes.INTEGER,
        allowNull: false,
      },
      model_id: {
        type: DataTypes.INTEGER,
        allowNull: false,
      },
      country_id: {
        type: DataTypes.INTEGER,
        allowNull: true,
      },
    },
    {
      createdAt: false,
      updatedAt: false,
    },
  );

  projects.associate = function (models) {
    projects.belongsTo(models.confidential_types, {
      foreignKey: {
        name: 'confidential_type_id',
        field: 'confidential_type_id',
      },
      onDelete: 'CASCADE',
      onUpdate: 'CASCADE',
    });
    projects.belongsTo(models.agents, {
      foreignKey: {
        name: 'agent_id',
        field: 'agent_id',
      },
      onDelete: 'CASCADE',
      onUpdate: 'CASCADE',
    });
    projects.belongsTo(models.customers, {
      foreignKey: {
        name: 'customer_id',
        field: 'customer_id',
      },
      onDelete: 'CASCADE',
      onUpdate: 'CASCADE',
    });
    projects.belongsTo(models.countries, {
      foreignKey: {
        name: 'country_id',
        field: 'country_id',
      },
      onDelete: 'CASCADE',
      onUpdate: 'CASCADE',
    });
    projects.belongsTo(models.engagement_category, {
      foreignKey: {
        name: 'category_id',
        field: 'category_id',
      },
      onDelete: 'CASCADE',
      onUpdate: 'CASCADE',
    });
    projects.belongsTo(models.engagement_model, {
      foreignKey: {
        name: 'model_id',
        field: 'model_id',
      },
      onDelete: 'CASCADE',
      onUpdate: 'CASCADE',
    });
    projects.hasMany(models.project_needs, {
      foreignKey: {
        name: 'project_id',
        field: 'id',
        allowNull: false,
      },
      onUpdate: 'CASCADE',
      onDelete: 'CASCADE',
    });
    projects.hasMany(models.project_history, {
      foreignKey: {
        name: 'project_id',
        field: 'id',
        allowNull: false,
      },
      onUpdate: 'CASCADE',
      onDelete: 'CASCADE',
    });
    projects.hasMany(models.engagement_information, {
      foreignKey: {
        name: 'project_id',
        field: 'id',
        allowNull: false,
      },
      onUpdate: 'CASCADE',
      onDelete: 'CASCADE',
    });
    projects.hasMany(models.employee_allocations, {
      foreignKey: {
        name: 'project_id',
        field: 'id',
        allowNull: false,
      },
      onUpdate: 'CASCADE',
      onDelete: 'CASCADE',
    });
  };

  return projects;
};
