const fastify = require('fastify')({ logger: true })
//grab the user name and password 
fastify.get('/', async (request, reply) => {
    return { hello: 'world' }
})