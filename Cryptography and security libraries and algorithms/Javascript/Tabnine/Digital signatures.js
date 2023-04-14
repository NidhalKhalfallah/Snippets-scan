Which size does the key have?

const crypto = require('crypto');

// Generate a DSA key
const Mykey = crypto.createDiffieHellman( 'prime256v1' );
