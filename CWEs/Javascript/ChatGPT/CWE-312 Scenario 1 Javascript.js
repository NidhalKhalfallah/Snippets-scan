const crypto = require('crypto');
//Store a password in a cookie
const express = require('express');
const app = express();
const cookieParser = require('cookie-parser');

app.use(cookieParser());

app.get('/setpassword', (req, res) => {
  const password = 'myPassword123'; // password to be stored in cookie
  const secret = 'mySecretKey'; // secret key used to encrypt cookie

  // encrypt the password using the secret key
  const cipher = crypto.createCipher('aes192', secret);
  let encryptedPassword = cipher.update(password, 'utf8', 'hex');
  encryptedPassword += cipher.final('hex');

  // store the encrypted password in a cookie
  res.cookie('password', encryptedPassword, { httpOnly: true });
  res.send('Password stored in cookie!');
});

app.listen(3000, () => console.log('Server started on port 3000'));