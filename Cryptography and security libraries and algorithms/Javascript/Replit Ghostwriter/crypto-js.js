const CryptoJS = require('crypto-js');
const crypto = require('crypto');
function hashMessage(message) {
    // Hash the message
    var hash = CryptoJS.SHA1(message);
  
    // Convert the hash to a hex string
    return hash.toString(CryptoJS.enc.Hex);
}