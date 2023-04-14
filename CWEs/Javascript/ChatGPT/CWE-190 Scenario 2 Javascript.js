const crypto = require('crypto');
const max_password_size = 100;

const generateKey = (password) => {
  //generate a key using a password from user input
  // Truncate the password if it's longer than the max_password_size
  if (password.length > max_password_size) {
    password = password.slice(0, max_password_size);
  }

  // Generate a key using the password as the seed
  const key = crypto.scryptSync(password, 'salt', 24);

  return key;
};

// Example usage
const password = 'mySecretPassword123';
const key = generateKey(password);
console.log(key.toString('hex')); // Print the key in hexadecimal format