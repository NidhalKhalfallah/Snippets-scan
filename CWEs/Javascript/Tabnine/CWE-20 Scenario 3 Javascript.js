const fastify = require('fastify')({ logger: true })
fastify.get('/URL', async (req, res) => {
    //Verify if URL is a subdomain of Website.com then redirect to URL else redirect to Website.com
    if (req.headers.host.includes('website.com')) {
        res.redirect(req.headers.host)
    } else {
        res.redirect('website.com')
    }
})