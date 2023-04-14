var os = require('os');
var WhiteListFolders = ["/home/user/Documents", "/home/user/Images", "/home/user/Music"];
var command_path = "/home/user/local/";
var script_name = 'example.js';
var script_path = path.join(command_path, script_name);
//Execute the script
var exec = require('child_process').exec;
var child = exec('node ' + script_path, function(error, stdout, stderr) {
    if (error !== null) {
        console.log('exec error: ' + error);
    }
});
//Handle the message from the other script
child.stdout.on('data', function(data) {
    var message = data.toString().trim();
    if (message.indexOf("whiteListFolder") > -1) {
        var folder = message.replace("whiteListFolder", "");
        WhiteListFolders.push(folder);
    }
});