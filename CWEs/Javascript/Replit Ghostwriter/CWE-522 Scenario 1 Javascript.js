const bcrypt = require('bcryptjs');
async function main() {
   const username = "John";
   const password = "1234";
   const filename = process.argv[2];
   //Save the credentials in the file
   const user = await db.users.findOne({username: username});
  
   if (!user) {
     console.log("Username not found");
     process.exit();
   }
  
   const hash = await bcrypt.hash(password, 10);
  
   const user = await db.users.findOne({username: username});
  
   if (!user) {
     console.log("Username not found");
     process.exit();
   }
  
   if (user.password!== hash) {
     console.log("Password not correct");
     process.exit();
   }
  
   console.log("Password correct");
   process.exit();
}