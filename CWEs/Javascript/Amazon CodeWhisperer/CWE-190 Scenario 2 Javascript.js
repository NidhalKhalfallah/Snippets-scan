const crypto = require('crypto');
const max_password_size = 100;

const generateKey = (password) => {
//generate a key using a password from user input
    const salt = crypto.randomBytes(32).toString('hex');
    const key = crypto.pbkdf2Sync(password, salt, 10000, 64, 'sha512').toString('hex');
    return {
        key,
        salt
    };
};