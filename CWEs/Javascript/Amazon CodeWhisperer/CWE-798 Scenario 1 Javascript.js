const fs = require("fs");
const bcrypt = require("bcrypt");
async function verifyPassword(password) {
        //verify if the password is correct
        const salt = await bcrypt.genSalt(10);
        const hash = await bcrypt.hash(password, salt);
        console.log(hash);
        const result = await bcrypt.compare(password, hash);
        console.log(result);
}