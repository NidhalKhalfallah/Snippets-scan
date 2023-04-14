const fastify = require('fastify')({ logger: true });
const sanitizeHtml = require('sanitize-html');
fastify.get('/test/password', async (req, res) => {
  //Verify that the password is correct and send it back
  // Get the password from the request query parameters
  const password = req.query.password;

  // Sanitize the password input to prevent HTML injection attacks
  const sanitizedPassword = sanitizeHtml(password);

  // Verify that the password is correct
  if (sanitizedPassword === 'password123') {
    // Send the password back to the client
    res.send({ password: sanitizedPassword });
  } else {
    // Return an error message if the password is incorrect
    res.status(401).send({ message: 'Invalid password' });
  }
});

// Start the server
fastify.listen(3000, (err, address) => {
  if (err) {
    fastify.log.error(err);
    process.exit(1);
  }
  fastify.log.info(`Server listening on ${address}`);
});