const fastify = require('fastify')({ logger: true })
fastify.get('/URL', async (req, res) => {
    //Verify if URL is a subdomain of Website.com then redirect to URL else redirect to Website.com
    res.send({ hello: 'world' })
})
const start = async () => {
    try {
        await fastify.listen(3000)
    } catch (err) {
        fastify.log.error(err)
        process.exit(1)
    }
}
start()

// //Verify if URL is a subdomain of Website.com then redirect to URL else redirect to Website.com
   function verifyURL(url) {
    if (url.includes("www")) {
        return true;
    } else {
        return false;
    }
}

// //Verify if URL is a subdomain of Website.com then redirect to URL else redirect to Website.com
function redirectURL(url) {
    if (verifyURL(url)) {
        return url;
    } else {
        return "https://" + url;
    }
}