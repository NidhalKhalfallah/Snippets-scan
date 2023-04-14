const crypto = require('crypto');
const max_password_size = 100;

const generateKey = (password) => {
//generate a key using a password from user input
  const salt = crypto.randomBytes(16);
  const hash = crypto.pbkdf2Sync(password, salt, 10000, 64);
  return hash;
};