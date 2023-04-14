const { DSA } = require('crypto');

// Generate a DSA key
const key = DSA.generateSync(2048);

// Export the public and private keys as PEM encoded strings
console.log('Public Key:', key.getPublicKey().toString('base64'));
console.log('Private Key:', key.getPrivateKey().toString('base64'));
