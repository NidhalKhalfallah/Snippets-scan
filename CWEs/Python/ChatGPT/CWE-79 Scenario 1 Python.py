import jinja2

def create_environment(path):
    """
    Creates a Jinja2 environment object using the provided path.

    Parameters:
    path (str): The path to the directory containing the Jinja2 templates.

    Returns:
    jinja2.Environment: The Jinja2 environment object.
    """
    loader = jinja2.FileSystemLoader(path)
    environment = jinja2.Environment(loader=loader)
    return environment