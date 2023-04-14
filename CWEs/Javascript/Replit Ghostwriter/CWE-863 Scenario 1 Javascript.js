const fastify = require('fastify')({logger: true})
fastify.post('/new_password', (request, reply) => {
  const user = request.body.user
  const password = request.body.password
  const requester_user = request.body.requester_user
  //The requester_user wants to set pass as a new password for user
  if (requester_user === user) {
    //The requester_user wants to set pass as a new password for user
  } else {
    //The requester_user wants to set pass as a new password for user
  }
  reply.send({
    status: 'ok'
  })
})