const { customers } = require('../models/index');
const { DEFAULT_PAGE_LIMIT, ZERO } = require('../utils/constants');

const addCustomer = async (req, res) => {
  /*
    #swagger.tags = ['customer']
    #swagger.summary = 'Create customer'
    #swagger.description = 'Trying to create new customer'
    #swagger.operationId = 'createCustomer'
  */
  try {
    const {
      name,
      address,
      email,
      phone: contact_phone,
      info: about,
    } = req.body;
    const data = await customers.create({
      name,
      address,
      email,
      contact_phone,
      about,
    });
    res.send(data);
  } catch (error) {
    res.status(500).send(error);
  }
};

const getAllCustomers = async (req, res) => {
  /*
    #swagger.tags = ["customer"]
    #swagger.summary = "Show all customers"
    #swagger.description = "Trying to get all customers"
    #swagger.operationId = "allCustomers"
  */
  try {
    if (Object.keys(req.query).length) {
      const getPagination = (page, size) => {
        const limit = size ? size : DEFAULT_PAGE_LIMIT;
        const offset = page ? page * limit : ZERO;
        return { limit, offset };
      };

      const getPagingData = (data, page, limit) => {
        const { count: totalItems, rows: customers } = data;
        const currentPage = page ? page : ZERO;
        const totalPages = Math.ceil(totalItems / limit);
        return { totalItems, customers, totalPages, currentPage };
      };

      const { page, size, sortBy } = req.query;
      const { limit, offset } = getPagination(page, size);
      await customers
        .findAndCountAll({
          limit,
          offset,
          order: [[sortBy || 'id']],
        })
        .then((data) => {
          const response = getPagingData(data, page, limit);
          res.send(response);
        });
    } else {
      const { count, rows } = await customers.findAndCountAll();
      res.send({ totalItems: count, customers: rows });
    }
  } catch (error) {
    res.status(500).send(error);
  }
};

const updateCustomer = async (req, res) => {
  /*
    #swagger.tags = ["customer"]
    #swagger.summary = "Update customer"
    #swagger.description = "Trying to update concrete customer data"
    #swagger.operationId = "updateCustomer"
  */
  try {
    const { name, address, email, phone: contact_phone, about } = req.body;
    const data = await customers.update(
      { name, address, email, contact_phone, about },
      {
        where: {
          id: req.params.customerId,
        },
        returning: true,
      },
    );
    res.send(data);
  } catch (error) {
    res.status(500).send(error);
  }
};

const deleteCustomer = async (req, res) => {
  /*
    #swagger.tags = ["customer"]
    #swagger.summary = "Delete customer"
    #swagger.description = "Trying to delete customer data"
    #swagger.operationId = "deleteCustomer"
  */
  try {
    const { customerId: id } = req.params;
    await customers.destroy({ where: { id } });
    res.send({ id });
  } catch (error) {
    res.status(500).send(error);
  }
};

module.exports = {
  getAllCustomers,
  addCustomer,
  updateCustomer,
  deleteCustomer,
};
