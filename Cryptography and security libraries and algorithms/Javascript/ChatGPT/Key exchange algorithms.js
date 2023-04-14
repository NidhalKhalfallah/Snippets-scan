const { DSA } = require('crypto');

// Generate a DSA key
const { publicKey, privateKey } = crypto.generateKeyPairSync('dsa', {
  modulusLength: 2048,
  hash: 'sha256',
});