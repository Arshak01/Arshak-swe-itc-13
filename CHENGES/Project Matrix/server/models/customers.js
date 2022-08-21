'use strict';

module.exports = (sequelize, DataTypes) => {
  const customers = sequelize.define(
    'customers',
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
      email: {
        type: DataTypes.STRING(50),
        allowNull: true,
      },
      contact_phone: {
        type: DataTypes.JSON,
        allowNull: true,
      },
      address: {
        type: DataTypes.STRING(50),
        allowNull: true,
      },
      about: {
        type: DataTypes.STRING(255),
        allowNull: true,
      },
    },
    {
      createdAt: false,
      updatedAt: false,
    },
  );

  customers.associate = function (db) {
    customers.hasMany(db.projects, {
      foreignKey: {
        name: 'customer_id',
        field: 'id',
        allowNull: false,
      },
      onUpdate: 'CASCADE',
      onDelete: 'CASCADE',
    });
  };

  return customers;
};
