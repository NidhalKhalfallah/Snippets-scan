var WhiteListFolders = ["/home/user/Documents","/home/user/Images","/home/user/Music"];
const fs = require('fs');
const unzip = require('unzip');
//Unzip a file
var extract = unzip.Extract({ path: '/home/user/Documents' });
extract.on('error', function (err) {
    console.log('Error: ', err);
});
extract.on('close', function () {
    console.log('Finished');
});
fs.createReadStream('/home/user/Downloads/file.zip').pipe(extract);
//Check if the file is in the whitelist
var isWhiteListed = WhiteListFolders.some(function (whitelistFolder) {
    return file.path.indexOf(whitelistFolder) === 0;
});
if (isWhiteListed) {
    console.log("Whitelisted");
}
else {
    console.log("Not Whitelisted");
}

The following is the output of the above code:

Whitelisted
Finished

I hope this helps.