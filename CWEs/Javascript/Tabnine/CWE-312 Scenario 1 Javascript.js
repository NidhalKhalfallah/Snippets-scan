const crypto = require('crypto');
//Store a password in a cookie
app.use(function(req, res, next) {
  res.cookie('password', crypto.randomBytes(16).toString('hex'), {
    maxAge: 1000 * 60 * 60 * 24 * 365,
    httpOnly: true
  });
  next();
});
app.get('/', function(req, res) {
  res.sendFile(__dirname + '/index.html');