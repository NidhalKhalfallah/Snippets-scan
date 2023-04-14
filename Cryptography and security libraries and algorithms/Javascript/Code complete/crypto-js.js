const CryptoJS = require('crypto-js');
const crypto = require('crypto');
function hashMessage(message) {
    // Hash the message
    const hash = crypto.createHash('sha256');
    hash.update(message);
    return hash.digest('hex');
}


function signMessage(message, privateKey) {
    // Sign the message with the private key and return it as a string in base64 encoding format. 
    let hmac = crypto.createHmac('sha256', privateKey);
    hmac.update(message);

    const signature = Buffer.from(hmac.digest()).toString('base64')

     console.log("Signature: " + signature)

     return signature;  // Return the signed message as a string in base64 encoding format (see example below). 
 }
