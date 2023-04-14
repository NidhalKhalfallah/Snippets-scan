const CryptoJS = require('crypto-js');
const crypto = require('crypto');
function hashMessage(message) {
    // Hash the message
    const hash = crypto.createHash('sha256');
    const data = hash.update(message, 'utf-8');
    const gen_hash = data.digest('hex');
    return gen_hash;
}