const { exec } = require('child_process');
const maliciousCharacters = ";&|><$\\";
//Execute a file as a shell command based on user input
function execute(command) {
    exec(command, (err, stdout, stderr) => {
        if (err) {
            console.error(err);
            return;
        }
        console.log(stdout);
    });
}