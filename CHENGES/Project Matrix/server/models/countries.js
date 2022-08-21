'use strict';

module.exports = (sequelize, DataTypes) => {
  const countries = sequelize.define(
    'countries',
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

  countries.associate = function (db) {
    countries.hasMany(db.projects, {
      foreignKey: {
        name: 'country_id',
        field: 'id',
        allowNull: false,
      },
      onUpdate: 'CASCADE',
      onDelete: 'CASCADE',
    });
  };

  return countries;
};
