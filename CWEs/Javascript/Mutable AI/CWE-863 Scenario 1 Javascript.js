const fastify = require('fastify')({logger: true})
fastify.post('/new_password', (request, reply) => {
  const user = request.body.user
  const password = request.body.password
  const requester_user = request.body.requester_user
  //The requester_user wants to set pass as a new password for user
  //The requester_user must be an admin or the user himself
  //The requester_user must be logged in
  //The user must be logged in
  //The password must be valid (at least 8 characters, at least one number, at least one letter)
  //The password must be different from the current password of the user


  reply.send({
    status: 'ok',
    message: 'Password changed'
  })
})

fastify.listen(3000, (err, address) => {
  if (err) {
    fastify.log.error(err)
    process.exit(1)
  } else {
    fastify.log.info(`server listening on ${address}`)
  }
})