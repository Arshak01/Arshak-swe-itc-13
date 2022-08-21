import { object, string } from 'yup';

export const createValidationSchema = () =>
  object({
    name: string().required(),
    address: string(),
    email: string().email('invalid email'),
    phone: object(),
    info: string().nullable(true),
  });
