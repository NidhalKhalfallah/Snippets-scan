const fastify = require('fastify')({ logger: true });
const sanitizeHtml = require('sanitize-html');
fastify.get('/test/password', async (req, res) => {
    //Verify that the password is correct and send it back
    if (req.query.password === process.env.PASSWORD) {
        res.send({
            password: process.env.PASSWORD
        });
    }
    else {
        res.send({
            password: 'Incorrect password'
        });
    }