'use strict';

module.exports = (sequelize, DataTypes) => {
  const confidential_types = sequelize.define(
    'confidential_types',
    {
      id: {
        allowNull: false,
        autoIncrement: true,
        primaryKey: true,
        type: DataTypes.INTEGER,
      },
      name: {
        type: DataTypes.ENUM({
          values: ['Standard', 'On Request', 'Strictly Private'],
        }),
        allowNull: false,
      },
    },
    {
      createdAt: false,
      updatedAt: false,
    },
  );

  confidential_types.associate = function (models) {
    confidential_types.hasMany(models.projects, {
      foreignKey: {
        name: 'confidential_type_id',
        field: 'id',
        allowNull: false,
      },
      onUpdate: 'CASCADE',
      onDelete: 'CASCADE',
    });
  };

  return confidential_types;
};
