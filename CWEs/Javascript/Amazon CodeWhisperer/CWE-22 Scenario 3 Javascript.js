var WhiteListFolders = ["/home/user/Documents","/home/user/Images","/home/user/Music"];
const fs = require('fs');
const unzip = require('unzip');
//Unzip a file
fs.createReadStream('test.zip')
    .pipe(unzip.Extract({ path: 'test' }));