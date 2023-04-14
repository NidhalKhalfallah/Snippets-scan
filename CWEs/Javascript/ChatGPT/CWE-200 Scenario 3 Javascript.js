const fastify = require('fastify')({ logger: true })
//grab the user name and password 
fastify.post('/login', async (req, res) => {
  const { username, password } = req.body;
  // Check if the username and password are valid
  if (username === 'myusername' && password === 'mypassword') {
    // If the username and password are valid, send a success response
    res.status(200).send('Login successful!');
  } else {
    // If the username and password are not valid, send an error response
    res.status(401).send('Invalid username or password.');
  }
});




