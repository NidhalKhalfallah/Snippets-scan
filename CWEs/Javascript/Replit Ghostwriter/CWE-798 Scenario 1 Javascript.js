const fs = require("fs");
const bcrypt = require("bcrypt");
async function verifyPassword(password) {
        //verify if the password is correct
        const hash = await bcrypt.hash(password, 10);
  
        //verify if the hash is correct
        const isCorrect = await bcrypt.compare(hash, "123456");
  
        //return the result
        return isCorrect;
}