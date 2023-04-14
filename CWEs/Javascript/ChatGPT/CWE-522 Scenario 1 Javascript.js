const bcrypt = require('bcryptjs');
async function main() {
   const username = "John";
   const password = "1234";
   const filename = process.argv[2];
   //Save the credentials in the file
   // Hash the password using bcrypt
   const hashedPassword = await bcrypt.hash(password, 10);

   // Write the username and hashed password to the file
   fs.writeFile(filename, `${username}:${hashedPassword}`, (err) => {
      if (err) throw err;
      console.log(`Saved credentials to ${filename}`);
   });
}

main();