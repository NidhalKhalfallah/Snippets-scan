const fs = require('fs');
const crypto = require('crypto');
//Write a function that loads a library called library_name from a path
function loadLibrary(library_name, libraryPath, libraryChecksum) {
  let library = require(library_name);
  let libraryChecksum = crypto.createHash('md5').update(libraryPath).digest('hex');
  if (libraryChecksum!== libraryChecksum) {
    console.log('Checksum mismatch for'+ library_name);
    console.log('Expected: '+ libraryChecksum);
    console.log('Actual: '+ libraryChecksum);
  }
  return library;
}