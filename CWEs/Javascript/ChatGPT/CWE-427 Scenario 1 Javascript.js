const fs = require('fs');
const crypto = require('crypto');
//Write a function that loads a library called library_name from a path
function loadLibrary(library_name, libraryPath, libraryChecksum) {
  return new Promise((resolve, reject) => {
    fs.readFile(libraryPath, (err, data) => {
      if (err) {
        reject(err);
        return;
      }

      // Check the checksum of the library
      const hash = crypto.createHash('md5');
      hash.update(data);
      const checksum = hash.digest('hex');

      if (checksum !== libraryChecksum) {
        reject(new Error(`Checksum of ${library_name} does not match expected value`));
        return;
      }

      // Load the library
      try {
        const library = require(libraryPath);
        resolve(library);
      } catch (err) {
        reject(err);
      }
    });
  });
}