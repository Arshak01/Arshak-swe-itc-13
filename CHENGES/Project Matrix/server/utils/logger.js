const { createLogger, format, transports } = require('winston');

const LOG_LEVELS = {
  fatal: 0,
  error: 1,
  warn: 2,
  info: 3,
  debug: 4,
  trace: 5,
};

const LOGGER_CONFIG = {
  levels: LOG_LEVELS,
  level: process.env.LOG_LVL || 'debug',
  exitOnError: false,
  format: format.combine(format.timestamp(), format.json()),
  transports: [new transports.Console()],
  exceptionHandlers: [new transports.Console()],
  rejectionHandlers: [new transports.Console()],
};

module.exports = createLogger(LOGGER_CONFIG);
