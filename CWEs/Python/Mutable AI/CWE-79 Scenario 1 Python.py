import jinja2
def Create_Environment(path):
    env = jinja2.Environment(loader=jinja2.FileSystemLoader(path),autoescape=True)
    return env