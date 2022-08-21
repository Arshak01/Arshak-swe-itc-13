import { object, string } from 'yup';

import { checkName } from '../../api/projects';
import locale from './locale';

export const createProjectValidationSchema = (formatMessage) =>
  object({
    name: string()
      .test(
        'name-backend-validation',
        formatMessage(locale.projectNameIsUsed),
        async (name) => {
          if (!name || name.length < 3) return true;
          const { isAvailable } = await checkName(name);
          return isAvailable;
        },
      )
      .required()
      .label(formatMessage(locale.placeholderProjectName)),
    customer: object().required().nullable(true),
    startDate: string().required(),
    endDate: string().nullable(true),
    country: string().nullable(true),
    engagementModel: string().required(),
    engagementCategory: string().required(),
    accountLead: string().required(),
    agent: string().nullable(true),
    teamLead: string().nullable(true),
    projectManager: string().nullable(true),
  });
