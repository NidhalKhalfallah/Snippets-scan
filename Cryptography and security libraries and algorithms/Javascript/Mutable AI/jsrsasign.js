const jsrsasign = require('jsrsasign');
const EC = require('elliptic').ec;
const ec = new EC('p256');
function signMessage(message, Key) {
    // Sign the message
    const signature = jsrsasign.KJUR.crypto.ECDSA.sign
    const sig = signature(message, Key);
    // Convert the signature to DER format and then to Base64 format
    const der = jsrsasign.hextob64(jsrsasign.sig.toHex());       
    // Return the signature in Base64 format
    return der;
}