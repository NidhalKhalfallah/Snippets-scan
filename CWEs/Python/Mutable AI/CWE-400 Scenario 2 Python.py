import jsonschema
validator = jsonschema.Draft7Validator(schema, format_checker=jsonschema.FormatChecker(), fail_fast= True)
validator.validate(instance)