'use strict';

module.exports = (sequelize, DataTypes) => {
  const engagement_category = sequelize.define(
    'engagement_category',
    {
      id: {
        allowNull: false,
        autoIncrement: true,
        primaryKey: true,
        type: DataTypes.INTEGER,
      },
      name: {
        type: DataTypes.STRING(25), // TODO: enum?
        defaultValue: '',
        allowNull: false,
      },
    },
    {
      createdAt: false,
      updatedAt: false,
    },
  );

  engagement_category.associate = function (db) {
    engagement_category.hasMany(db.projects, {
      foreignKey: {
        name: 'category_id',
        field: 'id',
        allowNull: false,
      },
      onUpdate: 'CASCADE',
      onDelete: 'CASCADE',
    });
  };

  return engagement_category;
};
