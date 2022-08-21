const fs = require('fs');
const formidable = require('formidable');
const path = require('path');

const {
  agents,
  projects,
  countries,
  customers,
  employees,
  hr_employee,
  employee_allocations,
  engagement_category,
  engagement_model,
  roles,
  positions,
  branches,
  confidential_types,
  Sequelize,
} = require('../models/index');

const DEFAULT_FIELTER_PARAM = {
  pageIndex: 1,
  pageSize: 100,
  sortBy: 'id',
};

const logger = require('../utils/logger');

const formProjectData = (data) => {
  const {
    name,
    startDate: start_date,
    endDate: end_date,
    about = null,
    technologyTools: technology_tools,
    budget,
    confidentialType: confidential_type_id, // TODO
    is_active,
    achievements_report,
    customerId: customer_id,
    categoryId: category_id,
    modelId: model_id,
    agentId: agent_id = null,
    countryId: country_id = null,
    logoUrl: logo_url = '',
    is_billable,
  } = data;

  const body = {};
  if (name) body['name'] = name;
  if (start_date) body['start_date'] = start_date;
  if (end_date) body['end_date'] = end_date;
  if (about) body['about'] = about;
  if (technology_tools) body['technology_tools'] = technology_tools;
  if (budget) body['budget'] = budget;
  if (confidential_type_id) body['confidential_type_id'] = confidential_type_id;
  if (typeof is_active == 'boolean') body['is_active'] = is_active;
  if (typeof achievements_report == 'boolean')
    body['achievements_report'] = achievements_report;
  if (customer_id) body['customer_id'] = customer_id;
  if (model_id) body['model_id'] = model_id;
  if (category_id) body['category_id'] = category_id;
  if (logo_url) body['logo_url'] = logo_url;
  if (typeof is_billable == 'boolean') body['is_billable'] = is_billable;
  if (agent_id) body['agent_id'] = agent_id;
  if (country_id) body['country_id'] = country_id;

  return body;
};

const endAllocation = async (id) => {
  await employee_allocations.update(
    { end_date: new Date() },
    {
      where: { id },
    },
  );
};

const updateAllocation = async (
  projectId,
  roleId,
  hr_employee_id,
  start_date = new Date(),
) => {
  const allocation = await employee_allocations.findOne({
    where: { role_id: roleId, project_id: projectId, end_date: null },
    attributes: [
      'id',
      [Sequelize.col('employee.hr_employee_id'), 'hr_employee_id'],
    ],
    includeIgnoreAttributes: false,
    include: employees,
    raw: true,
  });

  if (hr_employee_id) {
    const employee = await employees.findOne({
      where: { hr_employee_id },
      attributes: ['id'],
      raw: true,
    });

    const allocationData = {
      start_date,
      rate: 1,
      role_id: roleId,
      project_id: projectId,
      employee_id: employee.id,
    };
    if (!allocation) {
      const newAllocation = await employee_allocations.create(allocationData);
      return newAllocation;
    } else if (allocation && allocation.hr_employee_id !== hr_employee_id) {
      await endAllocation(allocation.id);
      const newAllocation = await employee_allocations.create(allocationData);
      return newAllocation;
    }
  } else if (allocation) {
    await endAllocation(allocation.id);
  }
};

const addProject = async (req, res) => {
  /*
    #swagger.tags = ['project']
    #swagger.summary = 'Create project'
    #swagger.description = 'Trying to create new project'
    #swagger.operationId = 'createProject'
  */

  try {
    const projectData = formProjectData(req.body);
    const newProject = await projects.create(projectData);
    const { startDate, accountLeadId, teamLeadId, projectManagerId } = req.body;

    const accountLeadData = await updateAllocation(
      newProject.id,
      3,
      accountLeadId,
      startDate,
    );

    logger.debug(
      'Employee allocation has been created for account lead with id - ',
      accountLeadData.id,
    );
    if (teamLeadId) {
      const teamLeadData = await updateAllocation(
        newProject.id,
        4,
        teamLeadId,
        startDate,
      );

      logger.debug(
        'Employee allocation has been created for team lead with id - ',
        teamLeadData.id,
      );
    }
    if (projectManagerId) {
      const projectManagerData = await updateAllocation(
        newProject.id,
        5,
        projectManagerId,
        startDate,
      );
      logger.debug(
        'Employee allocation has been created for Project lead with id - ',
        projectManagerData.id,
      );
    }
    res.send({ projectId: newProject.id, name: newProject.name });
  } catch (error) {
    res.status(500).send(error);
  }
};

const getAllProjects = async (req, res) => {
  /*
    #swagger.tags = ['project']
    #swagger.summary = 'Show all project'
    #swagger.description = 'Trying to get all projects param and without that.'
    #swagger.operationId = 'allProjects'
    #parameters:
    - in: pageIndex
      name: page index
      description: Give page index, default 0.
    - in: pageSize
      name: page size
      description: Give page size, default 100.
    - in: sortBy
      name: page sort
      description: Give page sortBy, default page sort by ID.
  */

  try {
    const getPagination = (pageIndex, pageSize) => {
      const offset = pageIndex
        ? pageIndex * pageSize
        : DEFAULT_FIELTER_PARAM.pageIndex;
      return { offset };
    };

    const getPagingData = (data, currentPage, limit) => {
      const { count: totalItems, rows: projects } = data;
      const totalPages = Math.ceil(totalItems / limit);
      return { totalItems, projects, totalPages, currentPage };
    };

    const { pageIndex, pageSize, sortBy } = Object.assign(
      {},
      DEFAULT_FIELTER_PARAM,
      req.query,
    );
    const { offset } = getPagination(pageIndex, pageSize);
    await projects
      .findAndCountAll({
        limit: pageSize,
        offset,
        order: [[sortBy]],
      })
      .then(async (data) => {
        const projectsData = getPagingData(data, pageIndex, pageSize);
        const customerIds = projectsData.projects.map(
          (project) => project.customer_id,
        );
        const customersData = await customers.findAll({
          where: {
            id: customerIds,
          },
        });
        const categoryIds = projectsData.projects.map(
          (project) => project.category_id,
        );
        const categoriesData = await engagement_category.findAll({
          where: {
            id: categoryIds,
          },
        });

        const countryIds = projectsData.projects
          .map((project) => project.country_id)
          .filter((item) => !!item);

        const countriesData = await countries.findAll({
          where: {
            id: countryIds,
          },
        });

        const modelIds = projectsData.projects.map(
          (project) => project.model_id,
        );
        const modelesData = await engagement_model.findAll({
          where: {
            id: modelIds,
          },
        });

        const agentIds = projectsData.projects
          .map((project) => project.agent_id)
          .filter((item) => !!item);
        const agentData = await agents.findAll({
          where: {
            id: agentIds,
          },
        });

        const projectsIds = projectsData.projects.map((project) => project.id);
        const employeesAllocations = await employee_allocations.findAll({
          where: {
            project_id: projectsIds,
            end_date: null,
          },
        });

        const employeesIds = employeesAllocations.map(
          (employee) => employee.employee_id,
        );
        const employeeData = await employees.findAll({
          where: {
            id: employeesIds,
          },
        });

        const hrEmployeesIds = employeeData.map(
          (employee) => employee.hr_employee_id,
        );
        const hrEmployeesData = await hr_employee.findAll({
          where: {
            id: hrEmployeesIds,
          },
        });

        const filledemployeesAllocations = employeesAllocations.map(
          (allocation) => {
            const employee = employeeData.find(
              ({ id }) => id === allocation.employee_id,
            );
            const hrEmployee = hrEmployeesData.find(
              ({ id }) => id === employee.hr_employee_id,
            );
            const fullAllocInfo = {
              ...allocation.toJSON(),
              employee: {
                displayName: `${hrEmployee.name} ${hrEmployee.surname}`,
                employeeId: employee.id,
              },
            };
            delete fullAllocInfo.employee_id;
            return fullAllocInfo;
          },
        );

        const filledProjectsData = projectsData.projects.map((project) => {
          const accountLead = filledemployeesAllocations.find(
            (allocation) => allocation.role_id === 3 && !allocation.end_date,
          );

          const projectManager = filledemployeesAllocations.find(
            (allocation) => allocation.role_id === 5 && !allocation.end_date,
          );
          const teamLead = filledemployeesAllocations.find(
            (allocation) => allocation.role_id === 4 && !allocation.end_date,
          );
          const customer = customersData.find(
            ({ id }) => id === project.customer_id,
          );
          const category = categoriesData.find(
            ({ id }) => id === project.category_id,
          );
          const country = countriesData.find(
            ({ id }) => id === project.country_id,
          );
          const agent = agentData.find(({ id }) => id === project.agent_id);

          const model = modelesData.find(({ id }) => id === project.model_id);
          const fullProject = {
            ...project.toJSON(),
            customer: customer && customer,
            country: country && country,
            agent: agent,
            engagementModel: model && model,
            engagementCategory: category && category,
            accountLead: accountLead?.employee?.displayName,
            projectId: project.id,
            isActive: project.is_active,
            isBillable: true,
            projectManager: projectManager?.employee?.displayName,
            teamLead: teamLead?.employee?.displayName,
          };
          delete fullProject.agent_id;
          delete fullProject.country_id;
          delete fullProject.customer_id;
          delete fullProject.category_id;
          delete fullProject.model_id;
          delete fullProject.id;
          delete fullProject.is_active;
          return fullProject;
        });
        res.send({
          items: filledProjectsData,
          totalItems: projectsData.totalItems,
          totalPages: projectsData.totalPages,
          currentPage: projectsData.currentPage,
        });
      });
  } catch (error) {
    res.status(500).send(error);
  }
};

const getProjectByName = async (req, res) => {
  /*
    #swagger.tags = ["project"]
    #swagger.summary = "Show a project"
    #swagger.description = "Trying to get a project by name"
    #swagger.operationId = "ProjectById"
  */
  try {
    const { projectId: name } = req.params;
    const data = await projects.findOne({
      where: {
        name: Sequelize.where(
          Sequelize.fn('LOWER', Sequelize.col('name')),
          'LIKE',
          `${name}%`, //TODO: trim
        ),
      },
      include: [
        {
          model: employee_allocations,
          attributes: ['id', 'start_date', 'end_date', 'rate'],
          include: [
            {
              model: employees,
              attributes: ['id'],
              include: [
                {
                  model: hr_employee,
                  attributes: ['id', 'name', 'surname'],
                },
                {
                  model: branches,
                  attributes: ['id', 'name'],
                },
                {
                  model: positions,
                  attributes: ['id', 'name'],
                },
              ],
            },
            {
              model: roles,
              attributes: ['id', 'name'],
            },
          ],
        },
        {
          model: confidential_types,
          attributes: ['id', 'name'],
        },
        {
          model: engagement_category,
          attributes: ['id', 'name'],
        },
        {
          model: customers,
        },
      ],
    });

    res.send(data || {});
  } catch (error) {
    res.status(500).send(error);
  }
};

const updateProject = async (req, res) => {
  /*
    #swagger.tags = ['project']
    #swagger.summary = 'Update project'
    #swagger.description = 'Trying to update concrete project data'
    #swagger.operationId = 'updateProject'
  */
  const projectData = await projects.findOne({
    where: {
      name: Sequelize.where(
        Sequelize.fn('LOWER', Sequelize.col('name')),
        'LIKE',
        `${req.params.projectId}%`,
      ),
    },
    attributes: ['id'],
  });
  const { project, customer, teamLead, projectManager, accountLead } = req.body;
  try {
    const data = await projects.update(formProjectData(project), {
      where: {
        id: projectData.id,
      },
      returning: true,
    });
    await customers.update(customer, { where: { id: project.customerId } });
    await updateAllocation(projectData.id, 3, accountLead);
    await updateAllocation(projectData.id, 4, teamLead);
    await updateAllocation(projectData.id, 5, projectManager);
    res.send(data);
  } catch (error) {
    res.status(500).send(error);
  }
};

const deleteProject = async (req, res) => {
  /*
    #swagger.tags = ['project']
    #swagger.summary = 'Delete project'
    #swagger.description = 'Trying to delete concrete project data'
    #swagger.operationId = 'deleteProject'
  */
  try {
    const { projectId: id } = req.params;
    await projects.destroy({ where: { id } });
    res.send({ id });
  } catch (error) {
    res.status(500).send(error);
  }
};

const uploadLogo = async (req, res) => {
  try {
    const form = new formidable.IncomingForm();
    form.parse(req).on('file', async (err, file) => {
      const tempPath = file.filepath;
      const extension = path.extname(file.originalFilename);
      const relativePath = `../assets/${req.params.projectId}${extension}`;
      const newpath = path.resolve(__dirname, relativePath);
      const fileData = fs.readFileSync(tempPath);
      fs.writeFile(newpath, fileData, (err) => {
        if (err) res.status(500).send(err);
        return res.send({ logo_url: relativePath });
      });
    });
  } catch (error) {
    res.status(500).send(error);
  }
};

module.exports = {
  getAllProjects,
  getProjectByName,
  addProject,
  updateProject,
  deleteProject,
  uploadLogo,
};
