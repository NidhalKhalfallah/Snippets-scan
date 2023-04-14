import jinja2
def Create_Environment(path):
    return jinja2.Environment(
        loader=jinja2.FileSystemLoader(path),
        extensions=['jinja2.ext.autoescape'],
        autoescape=True)
