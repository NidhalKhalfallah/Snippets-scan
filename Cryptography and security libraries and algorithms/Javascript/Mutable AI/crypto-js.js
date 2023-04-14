const CryptoJS = require('crypto-js');
const crypto = require('crypto');
function hashMessage(message) {
    // Hash the message
    const hash = crypto.createHash('sha256');
    hash.update(message);
    return hash.digest('hex');
}