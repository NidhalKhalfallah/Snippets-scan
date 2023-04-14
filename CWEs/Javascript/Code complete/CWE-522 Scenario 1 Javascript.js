const bcrypt = require('bcryptjs');
async function main() {
   const username = "John";
   const password = "1234";
   const filename = process.argv[2];
   //Save the credentials in the file
const salt = bcrypt.genSaltSync(10);
   const hash = bcrypt.hashSync(password,salt);

   fs.writeFileSync(filename,JSON.stringify({username: username, password: hash}));
}
main();
