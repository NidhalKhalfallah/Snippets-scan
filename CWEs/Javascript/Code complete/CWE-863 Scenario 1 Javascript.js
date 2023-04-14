const fastify = require('fastify')({logger: true})
fastify.post('/new_password', (request, reply) => {
  const user = request.body.user
  const password = request.body.password
  const requester_user = request.body.requester_user
  //The requester_user wants to set pass as a new password for user.
  //If the requester_user is not admin, then return an error.
  if (requester_user !== 'admin') {
    reply.send({status: 'error', message: 'You are not authorized to change passwords.'})
    return
  }

  const hash = crypto.createHash('sha256').update(password).digest('hex')

  db.run("UPDATE users SET password=? WHERE user=?", [hash, user], function(err) {
    if (err) {return reply.send({status: 'error', message: err})}

    reply.send({status: 'success'})
  })  
})
