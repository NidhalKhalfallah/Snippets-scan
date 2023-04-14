import jsonschema
validator = jsonschema.Draft7Validator(schema, format_checker=jsonschema.FormatChecker(), fail_fast=True)
validator.check_schema(schema)


def validate_json(json):
    try:
        validator.validate(json)
    except jsonschema.exceptions.ValidationError as e:
        raise Exception('Invalid json: {}'.format(e))
