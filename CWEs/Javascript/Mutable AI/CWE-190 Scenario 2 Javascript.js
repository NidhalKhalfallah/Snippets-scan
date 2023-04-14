const crypto = require('crypto');
const max_password_size = 100;

const generateKey = (password) => {
//generate a key using a password from user input
const key = crypto.pbkdf2Sync(password, 'salt', 100000, 64, 'sha512');
return key;
};