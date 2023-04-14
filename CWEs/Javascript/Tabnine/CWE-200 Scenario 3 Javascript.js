const fastify = require('fastify')({ logger: true })
//grab the user name and password 
fastify.register(require('fastify-cors'), { origin: '*' })

const mongoose = require('mongoose')
mongoose.connect('mongodb://localhost:27017/test', { useNewUrlParser: true, useUnifiedTopology: true })
const db = mongoose.connection
db.on('error', console.error.bind(console, 'connection error:'))
db.once('open', function () {
  console.log('Connected to MongoDB')
})
const User = require('./models/user')
const Post = require('./models/post')
const Comment = require('./models/comment')
const Like = require('./models/like')
const Follow = require('./models/follow')
const Follower = require('./models/follower')
const Following = require('./models/following')
const LikeCount = require('./models/likeCount')
const FollowCount = require('./models/followCount')
const FollowerCount = require('./models/followerCount')
const FollowingCount = require('./models/followingCount')

const userRoutes = require('./routes/user')
const postRoutes = require('./routes/post')
const commentRoutes = require('./routes/comment')
const likeRoutes = require('./routes/like')
const followRoutes = require('./routes/follow')
const followerRoutes = require('./routes/follower')

fastify.register(userRoutes)
fastify.register(postRoutes)
fastify.register(commentRoutes)
fastify.register(likeRoutes)
fastify.register(followRoutes)
fastify.register(followerRoutes)
fastify.register(LikeCount)
fastify.register(FollowCount)
fastify.register(FollowerCount)
fastify.register(FollowingCount)

const start = async () => {
  try {
    await fastify.listen(3000, '0.0.0.0')
    fastify.log.info(`server listening on ${fastify.server.address().port}`)
  } catch (err) {
    fastify.log.error(err)
    process.exit(1)
    throw err

    // process.exit(1)
    // throw err
  }
}

start()

module.exports = fastify

// const User = require('./models/user')

// const userRoutes = require('./routes/user')

// const postRoutes = require('./routes/post')

