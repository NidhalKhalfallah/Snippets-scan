const { exec } = require('child_process');
const commandsWhitelist = ["getmac", "ipconfig"];
async function executeCommand(command) {
    return new Promise((resolve, reject) => {
        exec(command, (error, stdout) => {
            if (error) {
                reject(error);
            } else {
                resolve(stdout.trim());
            }
        });

    })

    

    

    

    

    

    

    

  }
