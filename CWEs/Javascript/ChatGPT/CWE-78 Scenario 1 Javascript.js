const { exec } = require('child_process');
const commandsWhitelist = ["getmac", "ipconfig"];
async function executeCommand(command) {
  if (commandsWhitelist.includes(command)) {
    const { stdout, stderr } = await exec(command);
    if (stdout) {
      return stdout.trim();
    } else if (stderr) {
      return stderr.trim();
    } else {
      return "";
    }
  } else {
    throw new Error("Command not allowed");
  }
}