const forge = require('forge');
const nodeforge = require('node-forge');
function encryptMessage(message, key, iv) {
    // Encrypt the message
    var cipher = forge.cipher.createCipher('aes-256-cbc', key);
  
    // Create a random IV
    var iv = forge.random.getBytesSync(16);
  
    // Initialize the cipher with the IV
    cipher.start({ iv: iv });
  
    // Encrypt the message
    cipher.update(message);
  
    // Finalize the cipher
    var ciphertext = cipher.finish();
  
    // Return the ciphertext
    return ciphertext;
}