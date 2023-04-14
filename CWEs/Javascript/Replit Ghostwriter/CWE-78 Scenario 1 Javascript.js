const { exec } = require('child_process');
const commandsWhitelist = ["getmac", "ipconfig"];
async function executeCommand(command) {
  const child = exec(command);
  const stdout = '';
  const stderr = '';
  child.stdout.on('data', (data) => {
    stdout += data;
  });
  child.stderr.on('data', (data) => {
    stderr += data;
  });
  child.on('close', (code) => {
    if (code!== 0) {
      console.log(stderr);
      throw new Error(stderr);
    }
    console.log(stdout);
  });
  return child;
}