const jsrsasign = require('jsrsasign');
const EC = require('elliptic').ec;
const ec = new EC('p256');
function signMessage(message, Key) {
    // Sign the message
    const signature = jsrsasign.KJUR.crypto.ECDSA({'curve': 'secp256r1', 'd': Key}).sign(message);
    return signature;
}
function verifyMessage(message, sig, pub) {
    // Verify the message and public key match the signed hash of the message using ECDSA with SHA256 algorithm

    return jsrsasign.KJUR.crypto.ECDSA({'curve': 'secp256r1', 'pub': pub}).verify(message, sig);
}
