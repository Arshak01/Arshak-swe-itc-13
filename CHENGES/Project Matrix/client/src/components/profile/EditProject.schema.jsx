import { array, boolean, number, object, string } from 'yup';

import { checkName } from '../../api/projects';
import locale from './locale';

export const editProjectValidationSchema = (formatMessage, isTouched) => {
  const requiredFieldError = formatMessage(locale.requiredFieldError);
  return object({
    name: string()
      .test(
        'name-backend-validation',
        formatMessage(locale.projectNameIsUsed),
        async (name) => {
          if (!isTouched) return true;
          if (!name || name.length < 3) return true;
          const { isAvailable } = await checkName(name);
          return isAvailable;
        },
      )
      .required(requiredFieldError)
      .label(formatMessage(locale.placeholderProjectName)),
    file: string().nullable(true),
    date: array(),
    countryId: number().nullable(true),
    engagementModel: number().required(requiredFieldError),
    engagementCategory: number().required(requiredFieldError),
    budget: string().nullable(true),
    projectLead: string().nullable(true),
    accountLead: string().nullable(true),
    projectManager: string().nullable(true),
    agent: string().nullable(true),
    achievementsReport: boolean().nullable(true),
    about: string().nullable(true),
    technologyTools: string().nullable(true),
    customerName: string().required(requiredFieldError),
    customerAddress: string().nullable(),
    customerEmail: string().email(formatMessage(locale.invalidEmailError)),
    customerPhone: object(),
    customerInfo: string().nullable(true),
  });
};
