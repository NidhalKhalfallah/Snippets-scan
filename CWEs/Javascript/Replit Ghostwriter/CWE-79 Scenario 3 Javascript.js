const fastify = require('fastify')({ logger: true });
const sanitizeHtml = require('sanitize-html');
fastify.get('/test/password', async (req, res) => {
    //Verify that the password is correct and send it back to the client
            if (req.query.password === 'password') {
              res.send('Hello, World!');
            } else {
              res.send('Invalid password');
            }
  });