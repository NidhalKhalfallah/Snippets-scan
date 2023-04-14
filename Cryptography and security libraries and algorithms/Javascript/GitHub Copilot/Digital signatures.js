const crypto = require('crypto');

// Generate a DSA key
const Mykey = crypto.createDiffieHellman(1024);
Mykey.generateKeys();