const fastify = require('fastify')({ logger: true });
const sanitizeHtml = require('sanitize-html');
fastify.get('/test/password', async (req, res) => {
    //Verify that the password is correct and send it back
const password = req.query.password;
    if (password !== 'test') {
        res.send('Incorrect');
    } else {
        res.send(password);
    }

     //Verify that the password is correct and send it back with a sanitized version of the html in the body as well as a sanitized version of any url query params in the url string 

 });

 fastify.get('/test/html', async (req, res) => {
     //Verify that the password is correct and send it back with a sanitized version of the html in the body as well as a sanitized version of any url query params in the url string 

 });
