const crypto = require('crypto');

// Generate a DSA key
const Mykey = crypto.createDiffieHellman(2048);
Mykey.generateKeys();
const MyprivateKey = Mykey.getPrivateKey();
const MypublicKey = Mykey.getPublicKey();


// Generate a DSA key for the other party to use in Diffie-Hellman key exchange, and generate shared secret keys for each of them. 
const Otherkey = crypto.createDiffieHellman(2048);
Otherkey.generateKeys();
const OtherprivateKey = Otherkey.getPrivateKey();
const OtherpublicKey = Otherkey.getPublicKey();

 const Secret_shared_with_otherparty=Mykey._dh('hex',OtherpublicKey,'hex'); //this is the secret shared with the other party using Diffie Hellman Key Exchange method

 const Secret_shared_with_me=Otherkey._dh('hex',MypublicKey,'hex'); //this is the secret shared with me using Diffie Hellman Key Exchange method
