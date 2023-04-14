var os = require('os');
var WhiteListFolders = ["/home/user/Documents", "/home/user/Images", "/home/user/Music"];
var command_path = "/home/user/local/";
var script_name = 'example.js';
var script_path = path.join(command_path, script_name);
//Execute the script
var exec = require('child_process').exec;
exec('node ' + script_path, function(error, stdout, stderr) {
    console.log(stdout);
});