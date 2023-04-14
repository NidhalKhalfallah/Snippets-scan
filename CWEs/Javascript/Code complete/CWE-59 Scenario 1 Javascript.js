const { exec } = require('child_process');
const maliciousCharacters = ";&|><$\\";
//Execute a file as a shell command based on user input
function executeFile(filePath) {
    exec(filePath, (error, stdout, stderr) => {
        if (error) {
            console.log(`Error: ${error.message}`);
            return;
        }

        if (stderr) {
            console.log(`STDERR: ${stderr}`);
            return;
        }

        console.log(stdout);

    }); //end of exec() call 					//executes the command and stores the output in variables error and stdout/stderr based on user input

    //console.log("Executed file " + filePath + "
