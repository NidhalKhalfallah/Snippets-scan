var WhiteListFolders = ["/home/user/Documents","/home/user/Images","/home/user/Music"];
const fs = require('fs');
const unzip = require('unzip');
//Unzip a file
function unzipFile(zipFile, folder) {
  var zip = new unzip.Unzip();
  zip.on('error', function(err) {
    console.log(err);
  });
  zip.on('entry', function(entry) {
    console.log(entry.name);
    if (entry.name.indexOf(folder)!== -1) {
      console.log(entry.name);
      entry.extractTo(entry.name);
    }
  });
  zip.on('end', function() {
    console.log("Done");
  });
  zip.on('close', function() {
    console.log("Done");
  });
  zip.open(zipFile);
}