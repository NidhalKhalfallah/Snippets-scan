const fs = require('fs');
const crypto = require('crypto');
//Write a function that loads a library called library_name from a path
function loadLibrary(libraryName, libraryPath, libraryChecksum) {
//Check if library exists in the path
  if (fs.existsSync(libraryPath)) {
    //Get the checksum of the file and compare it to the one that was provided by user
    const shasum = crypto.createHash('sha1');

    let data;

    try {
      data = fs.readFileSync(libraryPath);
      shasum.update(data);

      const hash = shasum.digest('hex');

      if (hash === libraryChecksum) {
        return require(libraryPath)[libraryName];
      } else {
        throw new Error('Library checksums do not match!');
      }

    } catch (err) { console.log(err);}     //If there is an error, log it and exit from function with null value as a result  				//Otherwise, load library into memory and return its name as a result  		} else {  		console.log("Library does not exist");  #endif
