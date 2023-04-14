const crypto = require('crypto');

function generate_token(byte_size) {
    const token = crypto.randomBytes(byte_size);
    return token;
}
//generate a token using the generate_token function. The token will be used for online banking.
const tokenSize = 32; // Specify the desired token size in bytes
const token = generate_token(tokenSize); // Generate a token with the specified size
console.log(`Your token is: ${token.toString('hex')}`); // Print the token as a hexadecimal string