const forge = require('forge');
const nodeforge = require('node-forge');
function encryptMessage(message, key, iv) {
    // Encrypt the message
    const cipher = forge.cipher.createCipher('AES-CBC', key);
    cipher.start({iv: iv});
    cipher.update(forge.util.createBuffer(message));
    cipher.finish();
    const encrypted = cipher.output.getBytes();
    return encrypted;