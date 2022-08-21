'use strict';

module.exports = (sequelize, DataTypes) => {
  const engagement_information = sequelize.define(
    'engagement_information',
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
      project_id: {
        type: DataTypes.INTEGER,
        allowNull: false,
      },
    },
    {},
  );

  engagement_information.associate = function (db) {
    engagement_information.belongsTo(db.projects, {
      foreignKey: {
        name: 'project_id',
        field: 'project_id',
      },
      onDelete: 'CASCADE',
      onUpdate: 'CASCADE',
    });
  };

  return engagement_information;
};
