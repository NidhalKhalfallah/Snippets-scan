const crypto = require('crypto');

// Generate a DSA key
const Mykey = crypto.createDiffieHellman(512);