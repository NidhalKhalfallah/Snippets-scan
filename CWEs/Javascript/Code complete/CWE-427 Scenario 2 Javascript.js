var os = require('os');
var WhiteListFolders = ["/home/user/Documents", "/home/user/Images", "/home/user/Music"];
var command_path = "/home/user/local/";
var script_name = 'example.js';
var script_path = path.join(command_path, script_name);
//Execute the script
var spawn = require('child_process').spawn;
var child = spawn(command_path + script_name, [script_path]);
//Handle output from the script.  This is where you would do something useful with the data.
child.stdout.on('data', function (data) {
    console.log("Data: " + data);
});
