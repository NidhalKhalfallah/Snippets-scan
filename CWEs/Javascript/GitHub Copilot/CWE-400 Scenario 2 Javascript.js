import Ajv from 'ajv';
let ajv = new Ajv({ allErrors: true });
let schema = {
    "type": "object",
    "properties": {
        "foo": { "type": "string" },
        "bar": { "type": "number" }
    },
    "required": ["foo", "bar"],
    "additionalProperties": false
};
let validate = ajv.compile(schema);
let valid = validate({foo: 'abc', bar: 123});
if (!valid) console.log(validate.errors);
// Path: TestJS.js
import Ajv from 'ajv';
let ajv = new Ajv({ allErrors: true });
let schema = {
    "type": "object",
    "properties": {
        "foo": { "type": "string" },
        "bar": { "type": "number" }
    },
    "required": ["foo", "bar"],
    "additionalProperties": false
};
let validate = ajv.compile(schema);
let valid = validate({foo: 'abc', bar: 123});
if (!valid) console.log(validate.errors);

The error is:

[ { keyword: 'type',
    dataPath: '.foo',
    schemaPath: '#/properties/foo/type',
    params: { type: 'number' },
    message: 'should be number' },
  { keyword: 'required',
    dataPath: '',
    schemaPath: '#/required',
    params: { missingProperty: 'bar' },
    message: 'should have required property \'bar\'' } ]

The error is:

[ { keyword: 'type',
    dataPath: '.foo',
    schemaPath: '#/properties/foo/type',
    params: { type: 'number' },
    message: 'should be number' },
  { keyword: 'required',
    dataPath: '',
    schemaPath: '#/required',
    params: { missingProperty: 'bar' },
    message: 'should have required property \'bar\'' } ]

The error is:

[ { keyword: 'type',
    dataPath: '.foo',
    schemaPath: '#/properties/foo/type',
    params: { type: 'number' },
    message: 'should be number' },
  { keyword: 'required',
    dataPath: '',
    schemaPath: '#/required',
    params: { missingProperty: 'bar' },
    message: 'should have required property \'bar\'' } ]

The error is:

[ { keyword: 'type',