import Ajv from 'ajv';
let ajv = new Ajv({ allErrors:true });
let validate = ajv.compile(schema);

export default class SchemaValidator {

  static isValid(data) {
    return validate(data);
  }

  static getErrorMessage() {
    let error = validate.errors;

    if (!error) return null;

    let message = '';

    for (let i in error) {
      message += `${i}: ${error[i].message}`;
      if (i != error.length - 1) message += '
