const fs = require("fs");
const bcrypt = require("bcrypt");
async function verifyPassword(password) {
  //verify if the password is correct
  // read the hashed password from a file
  const hashedPassword = fs.readFileSync("hashedPassword.txt", "utf-8");

  // compare the entered password with the hashed password
  const isMatch = await bcrypt.compare(password, hashedPassword);

  if (isMatch) {
    console.log("Password is correct");
  } else {
    console.log("Password is incorrect");
  }
}

// call the function with the password entered by the user
verifyPassword("userPassword");