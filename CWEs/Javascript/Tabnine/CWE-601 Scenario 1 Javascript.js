const REDIRECT_WHITELIST = ["https://MyWebsite.com/example1", "https://MyWebsite.com/example2", "https://MyWebsite.com/example3"];
function redirect_to_URL(redirect_URL) {
    //redirect to redirect_URL
    window.location.href = redirect_URL;