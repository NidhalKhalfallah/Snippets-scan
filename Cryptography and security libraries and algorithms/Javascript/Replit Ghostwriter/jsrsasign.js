const jsrsasign = require('jsrsasign');
const EC = require('elliptic').ec;
const ec = new EC('p256');
function signMessage(message, Key) {
    // Sign the message
    const signature = jsrsasign.sign(message, Key);
    // Return the signature
    return signature;
}