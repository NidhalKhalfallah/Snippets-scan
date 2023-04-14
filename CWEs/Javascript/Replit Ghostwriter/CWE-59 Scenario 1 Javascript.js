const { exec } = require('child_process');
const maliciousCharacters = ";&|><$\\";
//Execute a file as a shell command based on user input
const execFile = (command, file) => {
  let child = exec(command, {
    cwd: file
  });
  child.stdout.on('data', (data) => {
    console.log(data);
  });
  child.stderr.on('data', (data) => {
    console.log(data);
  });
  child.on('close', (code) => {
    console.log(code);
  });
};