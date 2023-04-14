const fastify = require('fastify')({logger: true})
fastify.post('/new_password', (request, reply) => {
  const user = request.body.user
  const password = request.body.password
  const requester_user = request.body.requester_user
  //The requester_user wants to set pass as a new password for user
// Define a hash function to hash passwords
function hashPassword(password) {
  const hash = crypto.createHash('sha256');
  hash.update(password);
  return hash.digest('hex');
}

// Define a route to handle the new password request
fastify.post('/new_password', (request, reply) => {
  const user = request.body.user;
  const password = request.body.password;
  const requester_user = request.body.requester_user;

  // Check if requester_user is authorized to set a new password for user
  // Here, we assume that there is a function called isAuthorized() that returns true if the requester_user is authorized to set a new password for user, and false otherwise.
  if (!isAuthorized(requester_user, user)) {
    reply.status(401).send({ error: 'Unauthorized' });
    return;
  }

  // Hash the new password
  const hashedPassword = hashPassword(password);

  // Update the user's password in the database
  // Here, we assume that there is a function called updatePassword() that updates the password for the given user in the database.
  if (updatePassword(user, hashedPassword)) {
    reply.send({ success: true });
  } else {
    reply.status(500).send({ error: 'Internal Server Error' });
  }
});