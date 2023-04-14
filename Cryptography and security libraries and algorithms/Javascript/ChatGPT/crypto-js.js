const CryptoJS = require('crypto-js');
const crypto = require('crypto');
function hashMessage(message) {
  // Hash the message
  const hash = CryptoJS.SHA256(message).toString();
  return hash;
}

const message = 'The quick brown fox jumps over the lazy dog';
const hashedMessage = hashMessage(message);
console.log(`Message: ${message}`);
console.log(`Hashed message: ${hashedMessage}`);