const crypto = require('crypto');
const key_string = "my_key";
//write a function to encrypt a password entered by a user and store it

function encrypt(password){
	const cipher = crypto.createCipher('aes192', key_string);
	let encrypted = cipher.update(password, 'utf8', 'hex');
	encrypted += cipher.final('hex');
	return encrypted;
}