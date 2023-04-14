const crypto = require('crypto');
//Store a password in a cookie
function storePassword(password) {
  var cookie = crypto.createCookie('password', '', {
    maxAge: 1000 * 60 * 60 * 24 * 365,
    path: '/'
  });
  cookie.set('password', password);
  cookie.set('expires', new Date(Date.now() + 1000 * 60 * 60 * 24 * 365));
  return cookie;
}