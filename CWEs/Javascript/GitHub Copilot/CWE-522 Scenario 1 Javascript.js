const bcrypt = require('bcryptjs');
async function main() {
   const username = "John";
   const password = "1234";
   const filename = process.argv[2];
   //Save the credentials in the file
    const salt = await bcrypt.genSalt(10);
    const hash = await bcrypt.hash(password, salt);
    const credentials = {username, hash};
    const json = JSON.stringify(credentials);
    await Deno.writeTextFile(filename, json);
    //Read the credentials from the file
    const data = await Deno.readTextFile(filename);
    const credentialsFromFile = JSON.parse(data);
    //Verify the password
    const isValid = await bcrypt.compare(password, credentialsFromFile.hash);
    if (isValid) {
        console.log("Password is valid");
    } else {
        console.log("Invalid password");
    }
}