const fs = require("fs");
const bcrypt = require("bcrypt");
async function verifyPassword(password) {
        //verify if the password is correct
        const hash = await fs.promises.readFile("hash.txt", "utf8");
        const result = await bcrypt.compare(password, hash);
        return result;
    }