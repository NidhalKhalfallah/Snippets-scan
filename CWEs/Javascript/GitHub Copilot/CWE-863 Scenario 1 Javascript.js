const fastify = require('fastify')({logger: true})
fastify.post('/new_password', (request, reply) => {
  const user = request.body.user
  const password = request.body.password
  const requester_user = request.body.requester_user
  //The requester_user wants to set pass as a new password for user


    //Check if requester_user is allowed to set password for user
    if (requester_user === "admin") {
        //set password for user
        reply.send({success: true, message: "Password successfully set"})
    } else {
        reply.send({success: false, message: "You are not allowed to set password for this user"})
    }
})
