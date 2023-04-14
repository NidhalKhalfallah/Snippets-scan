import flask
Redirect_Whitelist = ["https://MyWebsite.com/example1", "https://MyWebsite.com/example2", "https://MyWebsite.com/example3"]
def redirect_to_URL(redirect_URL):
    #redirect to redirect_URL
    return flask.redirect(redirect_URL)
def redirect_to_Whitelist(redirect_URL):
    #redirect to redirect_URL if redirect_URL is in Redirect_Whitelist
    if redirect_URL in Redirect_Whitelist:
        return redirect_to_URL
        #redirect to redirect_URL if redirect_URL is not in Redirect_Whitelist
    else:
        return redirect_to_URL("https://MyWebsite.com/ ")
        #redirect to redirect_URL if redirect_URL is not in Redirect_Whitelist and redirect_URL is not in Redirect_Whitelist
        #return redirect_to_URL("https://MyWebsite.com/ ")