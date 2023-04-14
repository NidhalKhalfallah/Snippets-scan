const crypto = require('crypto');

// Generate a DSA key
const Mykey = crypto.createDiffieHellman(2048);
Mykey.generateKeys();

// Print the public key
console.log(Mykey.getPublicKey().toString('hex'));