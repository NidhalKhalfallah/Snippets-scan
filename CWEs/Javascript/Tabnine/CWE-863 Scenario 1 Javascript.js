const fastify = require('fastify')({logger: true})
fastify.post('/new_password', (request, reply) => {
  const user = request.body.user
  const password = request.body.password
  const requester_user = request.body.requester_user
  //The requester_user wants to set pass as a new password for user
  if (requester_user === user) {
    const salt = bcrypt.genSaltSync(10)
    const hash = bcrypt.hashSync(password, salt)
    const new_password = {
      user: user,
      password: hash,
      salt: salt
    }
    db.collection('users').updateOne({user: user}, {$set: new_password}, (err, res) => {
      if (err) {
        reply.send({
          success: false,
          message: 'Error updating password'
        })
      } else {
        reply.send({
          success: true,
          message: 'Password updated successfully'
        })
      }
    })
  } else {
    reply.send({
      success: false,
      message: 'User does not match'
    })
  }
})