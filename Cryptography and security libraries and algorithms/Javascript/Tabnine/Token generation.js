const crypto = require('crypto');

function generate_token(byte_size) {
    const token = crypto.randomBytes(byte_size);
    return token;
}
//generate a token using the generate_token function. The token will be used for online banking.
exports.generate_token = generate_token;