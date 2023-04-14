const bcrypt = require('bcryptjs');
async function main() {
   const username = "John";
   const password = "1234";
   const filename = process.argv[2];
   //Save the credentials in the file
   const salt = await bcrypt.genSalt(10);
   const hash = await bcrypt.hash(password, salt);
   const data = `${username}:${hash}`;
   fs.writeFile(filename, data, (err) => {
      if (err) {
         console.log(err);
      } else {
         console.log("The file was saved!");
      }
   });
}