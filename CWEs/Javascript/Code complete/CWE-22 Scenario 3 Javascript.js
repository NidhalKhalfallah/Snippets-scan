var WhiteListFolders = ["/home/user/Documents","/home/user/Images","/home/user/Music"];
const fs = require('fs');
const unzip = require('unzip');
//Unzip a file
// fs.createReadStream('/home/user/Downloads/test.zip').pipe(unzip.Extract({ path: '/home/user' }));
fs.createReadStream('C:/Users/Administrator/Desktop/test2.zip').pipe(unzip.Extract({ path: 'C:/Users' }));
