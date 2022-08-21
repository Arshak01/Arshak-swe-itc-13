const { employees, hr_employee } = require('../models/index');
const logger = require('../utils/logger');

// TODO: Need to import employee model from models

const addEmployee = async () => {
  /*
    #swagger.tags = ['employee']
    #swagger.summary = 'Create employee'
    #swagger.description = 'Trying to create new employee'
    #swagger.operationId = 'createEmployee'
  */
  try {
    // TODO: Need to add controller's body
  } catch (error) {
    // TODO: Need to add error description
  }
};

const getAllEmployees = async (req, res) => {
  /*
    #swagger.tags = ["employee"]
    #swagger.summary = "Show all employees"
    #swagger.description = "Trying to get all employees"
    #swagger.operationId = "allEmployees"
  */
  logger.debug(
    'get all employees has been invoked with query params ',
    req.query,
  );
  try {
    const { position } = req.query || {};
    const pids = [];
    if (position?.includes('account')) {
      pids.push(6);
    } else if (position?.includes('team')) {
      pids.push(6);
      pids.push(5);
    } else if (position?.includes('project')) {
      pids.push(4);
    }
    const query = pids.length
      ? { where: { status_id: 1, position_id: pids } }
      : {
          where: { status_id: 1 },
        };
    logger.debug('Employees query is', query);
    const employeesList = await employees.findAll(query);
    const hrIdsList = employeesList.map((employee) => employee.hr_employee_id);

    const hrList = await hr_employee.findAll({
      where: { id: hrIdsList },
      attributes: ['id', 'name', 'surname'],
    });
    res.send(hrList);
  } catch (error) {
    logger.error(error);
    res.send(500);
  }
};

const updateEmployee = async () => {
  /*
    #swagger.tags = ["employee"]
    #swagger.summary = "Update employee"
    #swagger.description = "Trying to update concrete employee data"
    #swagger.operationId = "updateEmployee"
  */
  try {
    // TODO: Need to add controller's body
  } catch (error) {
    // TODO: Need to add error description
  }
};

const deleteEmployee = async () => {
  /*
    #swagger.tags = ["employee"]
    #swagger.summary = "Delete employee"
    #swagger.description = "Trying to delete employee data"
    #swagger.operationId = "deleteEmployee"
  */
  try {
    // TODO: Need to add controller's body
  } catch (error) {
    // TODO: Need to add error description
  }
};

module.exports = {
  getAllEmployees,
  addEmployee,
  updateEmployee,
  deleteEmployee,
};
