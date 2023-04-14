const jsrsasign = require('jsrsasign');
const EC = require('elliptic').ec;
const ec = new EC('p256');
function signMessage(message, Key) {
    // Sign the message
    const key = ec.keyFromPrivate(Key);
    const sig = key.sign(message);
    // Convert signature to DER format
    const derSig = jsrsasign.KJUR.crypto.ECDSA.asn1SigToConcatSig(sig.toDER());
    // Return DER signature as hex
    return derSig.toString('hex');
}