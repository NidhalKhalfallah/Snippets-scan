const { exec } = require('child_process');
const maliciousCharacters = ";&|><$\\";
//Execute a file as a shell command based on user input

function executeShellCommand(command) {
    return new Promise((resolve, reject) => {
        exec(command, (error, stdout, stderr) => {
            if (error) {
                reject(error);
            } else {
                resolve(stdout);
            }
        });
    });
}