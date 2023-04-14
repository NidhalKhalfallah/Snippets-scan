const fastify = require('fastify')({ logger: true })
fastify.get('/URL', async (req, res) => {
    //Verify if URL is a subdomain of Website.com then redirect to URL else redirect to Website.com
    const URL = req.query.URL
    const Website = req.query.Website;
    const URL_REGEX = /^ *(?:(?:https?|ftp):\/\/)?(?:(?!(?:10|127)(?:\.\d{1,3}){3})(?!(?:169\.254|192\.168)(?:\.\d{1,3}){2})(?!172\.(?:1[6-9]|2\d |3[0-1])(?:\.\d{1,3}){2})(?:[1-9]\d?|1\d\d|2[01]\d|22[0-3])(?:\.(?:1?\d{1,2}|2[0-4]\d|25[
        //       \d]\d|[36]\d\d\d)){2}(?:\.(?:[1-9]\d?|1\d\d|2[0-4]\d|25[\d]\ d|[36]\d\d\d))|(?:(?:[a-z\u00a1-\uffff0-9]-*)*[a-
        //       z\u00a1-\uffff0-9]+)(?:\.(?:[a-z\u00a1-\uffff0-9]-*
        //       z\u00a1-\uffff0-9]+)*)*(?:\.(?:[a-z\u00a1-\uffff]{
            //       2,}))\.?)(?::\d{2,5})?(?:[/?#]\S*)?$/i
            if (URL_REGEX.test(URL)) {
                if (URL.includes (Website)) {
                    res.redirect(URL);
                } else {
                    res.redirect(Website);
                }
            } else {
                res. send('Invalid URL');
            }
        });