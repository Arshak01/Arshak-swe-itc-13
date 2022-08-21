'use strict';

module.exports = (sequelize, DataTypes) => {
  const hr_employee = sequelize.define(
    'hr_employee',
    {
      id: {
        allowNull: false,
        autoIncrement: true,
        primaryKey: true,
        type: DataTypes.INTEGER,
      },
      in_combination: {
        type: DataTypes.BOOLEAN,
        allowNull: false,
        defaultValue: false,
      },
      short_profile: {
        type: DataTypes.STRING(75),
        allowNull: false,
      },
      name: {
        type: DataTypes.STRING(50),
        allowNull: false,
      },
      surname: {
        type: DataTypes.STRING(50),
        allowNull: false,
      },
      email: {
        type: DataTypes.STRING(50),
        allowNull: false,
      },
      contact_phone: {
        type: DataTypes.STRING(25),
        allowNull: false,
      },
      date_of_birth: {
        type: DataTypes.DATE,
        allowNull: false,
      },
      gender_id: {
        type: DataTypes.INTEGER,
        allowNull: false,
      },
      social_id: {
        type: DataTypes.STRING(25),
        allowNull: false,
      },
      image: {
        type: DataTypes.STRING(255),
        allowNull: false,
      },
      id_namber: {
        type: DataTypes.STRING(40),
        allowNull: false,
      },
      id_document_type: {
        type: DataTypes.INTEGER,
        allowNull: false,
      },
      profassion: {
        type: DataTypes.STRING(50),
        allowNull: false,
      },
      family_status: {
        type: DataTypes.INTEGER,
        allowNull: false,
      },
      bank_account: {
        type: DataTypes.STRING(30),
        allowNull: false,
      },
    },
    {
      createdAt: false,
      updatedAt: false,
    },
  );

  hr_employee.associate = function (models) {
    hr_employee.hasMany(models.employees, {
      foreignKey: {
        name: 'hr_employee_id',
        field: 'id',
      },
      onDelete: 'CASCADE',
      onUpdate: 'CASCADE',
    });
  };

  return hr_employee;
};
