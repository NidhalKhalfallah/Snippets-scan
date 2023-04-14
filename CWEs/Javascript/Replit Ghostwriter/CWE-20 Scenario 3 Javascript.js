const fastify = require('fastify')({ logger: true })
fastify.get('/URL', async (req, res) => {
    //Verify if URL is a subdomain of Website.com then redirect to URL else redirect to Website.com
    if (req.url.indexOf('www.') === 0) {
      res.redirect('https://' + req.url)
    } else {
      res.redirect('https://www.website.com/' + req.url)
    }
  })