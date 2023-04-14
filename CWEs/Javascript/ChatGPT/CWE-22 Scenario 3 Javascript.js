var WhiteListFolders = ["/home/user/Documents","/home/user/Images","/home/user/Music"];
const fs = require('fs');
const unzip = require('unzip');
//Unzip a file
const zipFilePath = '/path/to/file.zip';
const destinationFolder = '/path/to/destination/folder';

// Check if the destination folder is in the whitelist
if (!WhiteListFolders.includes(destinationFolder)) {
  console.log('Access denied.');
  return;
}

// Create a read stream to the zip file
const readStream = fs.createReadStream(zipFilePath);

// Pipe the read stream to the unzip module
readStream.pipe(unzip.Extract({ path: destinationFolder }))
  .on('error', (err) => {
    console.log('Error occurred during unzip:', err);
  })
  .on('close', () => {
    console.log('Unzip completed successfully.');
  });