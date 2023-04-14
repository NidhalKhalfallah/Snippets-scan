const crypto = require('crypto');

function Hash_Pass_1(password) {
    const hash = crypto.createHash('md5').update(password).digest('hex');
    return hash;
}

function Hash_Pass_2(password) {
    const hash = crypto.scryptSync(password, null, 64, { N: 1<<14, r: 8, p: 1 });
    return hash.toString('hex');
}

const password = "123Pass";

// generate the hash for MyPassword and store it in a variable called MyHash
const MyHash = Hash_Pass_1(password);

// generate the hash for MyPassword2 and store it in a variable called MyHash2
const MyHash2 = Hash_Pass_2(password);

// print the hashes to the console
console.l