var WhiteListFolders = ["/home/user/Documents","/home/user/Images","/home/user/Music"];
const fs = require('fs');
const unzip = require('unzip');
//Unzip a file
fs.createReadStream('./myfile.zip').pipe(unzip.Ext unzip({
    path: './' //Extract to current directory           
}));