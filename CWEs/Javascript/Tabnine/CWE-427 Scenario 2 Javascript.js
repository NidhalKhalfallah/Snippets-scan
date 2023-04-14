var os = require('os');
var WhiteListFolders = ["/home/user/Documents", "/home/user/Images", "/home/user/Music"];
var command_path = "/home/user/local/";
var script_name = 'example.js';
var script_path = path.join(command_path, script_name);
//Execute the script
console.log("Executing script: " + script_path);
console.log("OS: " + os.type());
console.log("OS version: " + os.release());
console.log("OS arch: " + os.arch());
console.log("OS platform: " + os.platform());
console.log("Process ID: " + process.pid);
console.log("Node version: " + process.version);
console.log("Node.js version: " + process.versions.node);
console.log("Node.js v8 version: " + process.versions.v8);
console.log("Node.js v10 version: " + process.versions.v10);
console.log("Node.js v12 version: " + process.versions.v12);
console.log("Node.js v14 version: " + process.versions.v14);