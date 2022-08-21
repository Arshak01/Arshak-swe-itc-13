'use strict';

module.exports = (sequelize, DataTypes) => {
  const agents = sequelize.define(
    'agents',
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

  agents.associate = function (db) {
    agents.hasMany(db.projects, {
      foreignKey: {
        name: 'agent_id',
        field: 'id',
        allowNull: false,
      },
      onUpdate: 'CASCADE',
      onDelete: 'CASCADE',
    });
  };

  return agents;
};
