const { exec } = require('child_process');
const commandsWhitelist = ["getmac", "ipconfig"];
async function executeCommand(command) {
    return new Promise((resolve, reject) => {
        exec(command, (err, stdout, stderr) => {
            if (err) {
                reject(err);
                return;
            }
            resolve(stdout);
        });
    });
}