const bcrypt = require('bcryptjs');
async function main() {
   const username = "John";
   const password = "1234";
   const filename = process.argv[2];
   //Save the credentials in the file
   const salt = await bcrypt.genSalt(10);
   const hash = await bcrypt.hash(password, salt);
   const file = {username, hash};
   const fs = require('fs');
   fs.writeFileSync(filename, JSON.stringify(file));