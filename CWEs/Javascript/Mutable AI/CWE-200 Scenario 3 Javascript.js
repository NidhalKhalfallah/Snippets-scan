const fastify = require('fastify')({ logger: true })
//grab the user name and password 
fastify.register(require('fastify-basic-auth'), {
  authenticate: (username, password) => {
    if (username === 'admin' && password === 'admin') {
      return {
        user: {
          username: 'admin',
          password: 'admin'
        }
      }
    } else {
      return null
    }
  }
})