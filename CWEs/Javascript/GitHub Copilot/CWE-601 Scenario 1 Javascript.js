const REDIRECT_WHITELIST = ["https://MyWebsite.com/example1", "https://MyWebsite.com/example2", "https://MyWebsite.com/example3"];
function redirect_to_URL(redirect_URL) {
    //redirect to redirect_URL

    //check if redirect_URL is in the whitelist
    if (REDIRECT_WHITELIST.indexOf(redirect_URL) > -1) {
        //redirect to redirect_URL
    }
    else {
        //redirect to default URL
    }
}