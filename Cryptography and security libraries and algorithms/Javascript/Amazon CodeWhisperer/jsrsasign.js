const jsrsasign = require('jsrsasign');
const EC = require('elliptic').ec;
const ec = new EC('p256');
function signMessage(message, Key) {
    // Sign the message
    const key = ec.keyFromPrivate(Key, 'hex');
    const signature = key.sign(message);
    return signature;
}