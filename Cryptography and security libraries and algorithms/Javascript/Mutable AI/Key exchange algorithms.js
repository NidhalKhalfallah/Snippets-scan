const { DSA } = require('crypto');

// Generate a DSA key

const key = DSA.generatePrivateKey(
    {
        modulusLength: 1024,
        publicExponent: new Uint8Array([1, 0, 1]),
        //privateExponent: new Uint8Array([0x00, 0x00 ...]),
        //prime1: new Uint8Array([0x00, 0x00 ...]),
        //prime2: new Uint8Array([0x00, 0x00 ...]),
        //coefficient: new Uint8Array([0x00, 0x00 ...]),
        //otherPrimeInfos: [ { prime: new Uint8Array([0x00, 0x00 ...]),