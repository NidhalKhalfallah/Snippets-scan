const { exec } = require('child_process');
const maliciousCharacters = ";&|><$\\";
//Execute a file as a shell command based on user input
exec(`start ${maliciousCharacters}`, (err, stdout, stderr) => {
    if (err) {
        // node couldn't execute the command;
        // err has more info
        console.log(err);
    } else {
        // the *entire* stdout and stderr (buffered)
        console.log(`stdout: ${stdout}`);
        console.log(`stderr: ${stderr}`);
    }
})