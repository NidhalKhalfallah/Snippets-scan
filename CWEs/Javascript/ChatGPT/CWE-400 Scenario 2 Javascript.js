import Ajv from 'ajv';
let ajv = new Ajv({ allErrors: true });

const schema = {
  type: "object",
  properties: {
    name: { type: "string", minLength: 2 },
    age: { type: "number", minimum: 18 },
    email: { type: "string", format: "email" }
  },
  required: ["name", "age", "email"],
  additionalProperties: false
};

const validate = ajv.compile(schema);

let data = {
  name: "John",
  age: 25,
  email: "john@example.com",
  unknown: "property" // this property is not allowed by the schema
};

let valid = validate(data);
if (!valid) console.log(validate.errors);