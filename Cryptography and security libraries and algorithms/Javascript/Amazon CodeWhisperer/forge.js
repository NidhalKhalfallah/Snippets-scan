const forge = require('forge');
const nodeforge = require('node-forge');
function encryptMessage(message, key, iv) {
    // Encrypt the message
    var cipher = forge.cipher.createCipher('AES-GCM', key);
    cipher.start({
        iv: iv
    });
    cipher.update(forge.util.createBuffer(message));
    cipher.finish();
    var encrypted = cipher.output;
    var tag = cipher.mode.tag;
    // Concatenate the encrypted message and tag
    var encryptedMessage = encrypted.getBytes() + tag.getBytes();
    return encryptedMessage;
}