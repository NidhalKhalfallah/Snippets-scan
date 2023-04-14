import flask
Redirect_Whitelist = ["https://MyWebsite.com/example1", "https://MyWebsite.com/example2", "https://MyWebsite.com/example3"]
def redirect_to_URL(redirect_URL):
    #redirect to redirect_URL
    return flask.redirect(redirect_URL)
def check_redirect_URL(redirect_URL):
    if redirect_URL in Redirect_Whitelist:
        return redirect_to_URL(redirect_URL)
    else:
        return "Invalid URL"