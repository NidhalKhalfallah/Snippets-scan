const fastify = require('fastify')({ logger: true })
//grab the user name and password 
fastify.register(require('./index.js'))
fastify.listen(3000, () => {
  console.log('listening on port 3000')
})