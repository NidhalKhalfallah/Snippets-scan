const fs = require("fs");
const bcrypt = require("bcrypt");
async function verifyPassword(password) {
        //verify if the password is correct
const salt = await bcrypt.genSalt(10);
        const hash = await bcrypt.hash(password, salt);
        return hash;
    }

    async function verifyUserPassword(user, password) {
        //verify if the password is correct for a user 
        const savedHash = user.password;

        try {
            return await bcrypt.compare(password, savedHash); //returns true or false depending on whether the passwords match or not 

            //if (await bcrypt.compare(password, savedHash)) {

            //} else {

            //}

        } catch (err) { console.log("Error in verifyUserPassword", err) };
    }
