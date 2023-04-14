import jsonschema

validator = jsonschema.Draft7Validator(schema, format_checker=jsonschema.FormatChecker(), fail_fast=True)

def validate_data(data):
    try:
        validator.validate(data)
        return True
    except jsonschema.exceptions.ValidationError:
        return False