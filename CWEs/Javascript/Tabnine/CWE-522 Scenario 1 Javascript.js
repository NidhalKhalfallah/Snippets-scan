const bcrypt = require('bcryptjs');
async function main() {
   const username = "John";
   const password = "1234";
   const filename = process.argv[2];
   //Save the credentials in the file
   await saveCredentials(username, password, filename);
   //Load the credentials from the file
   const credentials = await loadCredentials(filename);
   //Check if the credentials are correct
   if (credentials.username === username && credentials.password === password) {
      console.log("Credentials are correct");
   } else {
      console.log("Credentials are incorrect");
   }