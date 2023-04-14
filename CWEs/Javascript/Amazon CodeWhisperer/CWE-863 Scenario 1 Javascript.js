const fastify = require('fastify')({logger: true})
fastify.post('/new_password', (request, reply) => {
  const user = request.body.user
  const password = request.body.password
  const requester_user = request.body.requester_user
  //The requester_user wants to set pass as a new password for user
  //The user is the user that is requesting the change
  //The password is the old password of the user
  //The new password is the new password of the user
  //The new password must be different from the old password
  //The new password must be at least 8 characters long
  //The new password must contain at least one number
  //The new password must contain at least one uppercase letter
  //The new password must contain at least one lowercase letter
  //The new password must contain at least one special character
  //The new password must not contain the old password
  //The new password must not contain the requester_user
  //The new password must not contain the user
  //The new password must not contain the requester_user
  //The new password must not contain the user
  //The new password must not contain the requester_user
  //The new password must not contain the user
  //The new password must not contain the requester_user

  reply.send({
    user: user,
    password: password,
    requester_user: requester_user
  })
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

// {
//   "user": "user",
//   "password": "password",
//   "requester_user": "requester_user",
//   "new_password": "new_password"
// }

// {
//   "user": "user",
//   "password": "password",
//   "requester_user": "requester_user",