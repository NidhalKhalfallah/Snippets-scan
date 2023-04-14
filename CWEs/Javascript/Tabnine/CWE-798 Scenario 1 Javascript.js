const fs = require("fs");
const bcrypt = require("bcrypt");
async function verifyPassword(password) {
        //verify if the password is correct
        const hash = await bcrypt.hash(password, 10);
        return hash;