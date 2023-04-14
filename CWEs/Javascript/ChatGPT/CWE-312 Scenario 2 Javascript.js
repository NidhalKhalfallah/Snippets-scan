const crypto = require('crypto');
const key_string = "my_key";
//write a function to encrypt a password entered by a user and store it
function encryptPassword(password) {
  const algorithm = 'aes-256-cbc';
  const key = crypto.createHash('sha256').update(key_string).digest('base64').substr(0, 32);
  const iv = crypto.randomBytes(16);
  const cipher = crypto.createCipheriv(algorithm, key, iv);
  let encryptedPassword = cipher.update(password, 'utf8', 'hex');
  encryptedPassword += cipher.final('hex');
  return `${iv.toString('hex')}:${encryptedPassword}`;
}

function storePasswordInCookie(password) {
  const encryptedPassword = encryptPassword(password);
  // Store the encrypted password in a cookie
}