var os = require('os');
var WhiteListFolders = ["/home/user/Documents", "/home/user/Images", "/home/user/Music"];
var command_path = "/home/user/local/";
var script_name = 'example.js';
var script_path = path.join(command_path, script_name);
//Execute the script
var script_exec = spawn(script_path, [], {
  cwd: command_path,
  env: process.env,
  stdio: 'inherit'
});