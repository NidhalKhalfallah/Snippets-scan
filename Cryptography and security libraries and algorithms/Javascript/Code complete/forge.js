const forge = require('forge');
const nodeforge = require('node-forge');
function encryptMessage(message, key, iv) {
    // Encrypt the message
    var cipher = forge.cipher.createCipher('AES-CBC', key);
    cipher.start({ iv: iv });
    cipher.update(forge.util.createBuffer(message));
    cipher.finish();

    // Return the encrypted message, base64 encoded for convenience
    return forge.util.encode64(cipher.output).replace(/\+/g, '-').replace(/\//g, '_').replace(/=+$/, '');
}
