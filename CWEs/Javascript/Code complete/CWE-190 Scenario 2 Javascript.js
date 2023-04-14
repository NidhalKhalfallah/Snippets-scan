const crypto = require('crypto');
const max_password_size = 100;

const generateKey = (password) => {
//generate a key using a password from user input
const salt = crypto.randomBytes(32).toString('hex');
  const iterations = 10000;
  const keyLength = 64;

  return new Promise((resolve, reject) => {
    crypto.pbkdf2(password, salt, iterations, keyLength, (err, derivedKey) => {
      if (err) reject(err);

      resolve({salt: salt, hash: derivedKey.toString('hex')});
    });
  });   //end promise function generateKey()

 };//end generateKey() function definition

 module.exports = {generateKey};
