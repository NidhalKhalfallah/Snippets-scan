const fastify = require('fastify')({ logger: true });
const sanitizeHtml = require('sanitize-html');
fastify.get('/test/password', async (req, res) => {
    //Verify that the password is correct and send it back
    const password = req.query.password;
    const sanitizedPassword = sanitizeHtml(password, {
        allowedTags: [],
        allowedAttributes: {}
    });
    res.send({ password: sanitizedPassword });
}