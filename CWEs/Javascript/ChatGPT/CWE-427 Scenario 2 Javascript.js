var os = require('os');
var WhiteListFolders = ["/home/user/Documents", "/home/user/Images", "/home/user/Music"];
var command_path = "/home/user/local/";
var script_name = 'example.js';
var script_path = path.join(command_path, script_name);
//Execute the script
const { spawn } = require('child_process');

// create an array of arguments for the script
const args = ['arg1', 'arg2', 'arg3'];

// spawn a new child process to run the script
const child = spawn('node', [script_path, ...args]);

// log any data that the script outputs to the console
child.stdout.on('data', (data) => {
  console.log(`stdout: ${data}`);
});

// log any error messages that the script outputs to the console
child.stderr.on('data', (data) => {
  console.error(`stderr: ${data}`);
});

// log a message when the script exits
child.on('close', (code) => {
  console.log(`child process exited with code ${code}`);
});