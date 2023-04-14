import flask
Redirect_Whitelist = ["https://MyWebsite.com/example1", "https://MyWebsite.com/example2", "https://MyWebsite.com/example3"]
def redirect_to_URL(redirect_URL):
    #redirect to redirect_URL if it is in the whitelist
    if redirect_URL in Redirect_Whitelist:
        return flask.redirect(redirect_URL)
    else:
        return flask.abort(404)