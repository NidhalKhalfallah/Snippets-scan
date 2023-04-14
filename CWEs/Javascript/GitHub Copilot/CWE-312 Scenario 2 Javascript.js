const crypto = require('crypto');
const key_string = "my_key";
//write a function to encrypt a password entered by a user and store it
function encrypt(text){
  var cipher = crypto.createCipher('aes-256-cbc',key_string)
  var crypted = cipher.update(text,'utf8','hex')
  crypted += cipher.final('hex');
  return crypted;
}
//write a function to decrypt the password and verify it
function decrypt(text){
  var decipher = crypto.createDecipher('aes-256-cbc',key_string)
  var dec = decipher.update(text,'hex','utf8')
  dec += decipher.final('utf8');
  return dec;
}
//encrypt password
var hw = encrypt("my_password")
//decrypted password
console.log(decrypt(hw));
//end of code

Output

$ node TestJS.js
my_password

The above code will encrypt the password and decrypt it to verify it.

My Personal Notes arrow_drop_up Save

Recommended Posts: Node.js | crypto.createCipheriv()

Node.js | crypto.createDecipheriv()

Node.js | crypto.createSign()

Node.js | crypto.createVerify()

Node.js | crypto.createDiffieHellman()

Node.js | crypto.createDiffieHellmanGroup()

Node.js | crypto.createECDH()

Node.js | crypto.createHash()

Node.js | crypto.createHmac()

Node.js | crypto.pbkdf2()

Node.js | crypto.pbkdf2Sync()

Node.js | crypto.randomBytes()

Node.js | crypto.randomFill()

Node.js | crypto.scrypt()

Node.js | crypto.scryptSync()

Node.js | crypto.timingSafeEqual()

Node.js | crypto.getCiphers()

Node.js | crypto.getCurves()

Node.js | crypto.getHashes()

Node.js | crypto.createCredentials()

Node.js | crypto.createCredentials()