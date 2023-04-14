import Ajv from 'ajv';
let ajv = new Ajv({ allErrors: true });
let validate = ajv.compile(schema);
let valid = validate(data);
if (!valid) {
  console.log(validate.errors);
}