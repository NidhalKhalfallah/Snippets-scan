var WhiteListFolders = ["/home/user/Documents","/home/user/Images","/home/user/Music"];
const fs = require('fs');
const unzip = require('unzip');
//Unzip a file
function unzipFile(file) {
    return new Promise((resolve, reject) => {
        fs.createReadStream(file)
           .pipe(unzip.Extract({ path: __dirname }))
           .on('close', () => {
                resolve();
            });
    });