const { DSA } = require('crypto');

// Generate a DSA key
const key = DSA.generateKeyPair();
console.log(key.publicKey);
console.log(key.privateKey);
console.log(key.publicKey.length);