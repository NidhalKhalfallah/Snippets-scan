const crypto = require('crypto');
const password = Buffer.from('password');
const userInput = Buffer.from('user-input');
//Log the user in if the password and user input match
// Generate the hash of user input using the same algorithm and parameters as the stored password hash
const hash = crypto.scryptSync(userInput, password.slice(0, 16), 32, { N: 16384, r: 8, p: 1 }).toString('hex');

// Compare the generated hash with the stored password hash
if (hash === password.slice(16).toString('hex')) {
  console.log('Login successful!');
} else {
  console.log('Login failed!');
}