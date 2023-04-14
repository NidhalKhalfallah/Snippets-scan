const { exec } = require('child_process');
const maliciousCharacters = ";&|><$\\";
//Execute a file as a shell command based on user input
const userInput = "filename.txt";

if (maliciousCharacters.split("").some(char => userInput.includes(char))) {
  console.log("Invalid input, contains malicious characters");
} else {
  exec(`cat ${userInput}`, (error, stdout, stderr) => {
    if (error) {
      console.error(`Error: ${error.message}`);
      return;
    }
    if (stderr) {
      console.error(`stderr: ${stderr}`);
      return;
    }
    console.log(`File contents: ${stdout}`);
  });
}