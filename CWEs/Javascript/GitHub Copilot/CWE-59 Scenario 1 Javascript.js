const { exec } = require('child_process');
const maliciousCharacters = ";&|><$\\";
//Execute a file as a shell command based on user input
function runCommand() {
    var command = document.getElementById("command").value;
    for (var i = 0; i < maliciousCharacters.length; i++) {
        if (command.indexOf(maliciousCharacters.charAt(i)) != -1) {
            alert("Malicious characters detected");
            return;
        }
            }
                exec(command, (err, stdout, stderr) => {
                    if (err) {
                        console.error(err);
                        return;
                    }
                    console.log(stdout);
                }
                            );
}