const forge = require('forge');
const node-forge = require('node-forge');
function encryptMessage(message, key, iv) {
  // Encrypt the message
  const cipher = forge.cipher.createCipher('AES-CBC', key);
  cipher.start({ iv: iv });
  cipher.update(forge.util.createBuffer(message));
  cipher.finish();
  const encryptedMessage = forge.util.encode64(cipher.output.getBytes());
  return encryptedMessage;
}