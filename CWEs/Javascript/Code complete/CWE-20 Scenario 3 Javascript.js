const fastify = require('fastify')({ logger: true })
fastify.get('/URL', async (req, res) => {
    //Verify if URL is a subdomain of Website.com then redirect to URL else redirect to Website.com
    const website = 'https://www.website.com'
    const url = req.query.url;
    if (url && url !== '' && url !== website) {
        if (isSubdomain(website, url)) {
            res.redirect(301, `${url}`);
        } else {
            res.redirect(301, `${website}`);
        }

    } else {

        //If URL is empty or Website then redirect to Website 

        res.redirect(301, `${website}`);

    }

     //Verify if URL is a subdomain of Website.com then redirect to URL else redirect to Website.com   .then((response) => {console.log('Response: ', response)}).catch((err) => console.log('Error: ', err));  })})
