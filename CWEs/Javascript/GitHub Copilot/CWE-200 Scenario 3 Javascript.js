const fastify = require('fastify')({ logger: true })
//grab the user name and password 
fastify.get('/user/:username/:password', (request, reply) => {
    reply.send({ username: request.params.username, password: request.params.password })
    })