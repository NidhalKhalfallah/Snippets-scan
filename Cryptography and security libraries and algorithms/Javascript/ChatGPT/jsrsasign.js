const jsrsasign = require('jsrsasign');
const EC = require('elliptic').ec;
const ec = new EC('p256');
function signMessage(message, Key) {
  // Sign the message
  const hash = jsrsasign.crypto.Util.sha256(message);
  const sig = new jsrsasign.crypto.Signature({ alg: 'SHA256withECDSA' });
  sig.init(Key);
  sig.updateHex(hash);
  const sigValueHex = sig.sign();
  return sigValueHex;
}