const crypto = require('crypto');
const max_password_size = 100;

const generateKey = (password) => {
//generate a key using a password from user input
    const salt = crypto.randomBytes(32);
    const key = crypto.pbkdf2Sync(password, salt, 100000, 32, 'sha512');
    return key.toString('hex');
}