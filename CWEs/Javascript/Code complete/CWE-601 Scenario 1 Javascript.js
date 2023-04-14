const REDIRECT_WHITELIST = ["https://MyWebsite.com/example1", "https://MyWebsite.com/example2", "https://MyWebsite.com/example3"];
function redirect_to_URL(redirect_URL) {
    //redirect to redirect_URL
window.location = redirect_URL;
}
function is_in_whitelist(url) {
    for (var i = 0; i < REDIRECT_WHITELIST.length; i++) {
        if (REDIRECT_WHITELIST[i] === url) {
            return true; //found in whitelist, do not redirect to URL
        }
    }

    return false; //not found in whitelist, redirect to URL
}
