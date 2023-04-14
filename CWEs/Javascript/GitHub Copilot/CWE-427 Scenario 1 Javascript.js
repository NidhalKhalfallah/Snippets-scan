const fs = require('fs');
const crypto = require('crypto');
//Write a function that loads a library called library_name from a path
function loadLibrary(library_name, libraryPath, libraryChecksum) {


    //Check if the library exists in the path
    if (fs.existsSync(libraryPath)) {
        //Check if the library checksum matches the checksum of the library in the path
        if (getChecksum(libraryPath) == libraryChecksum) {
            //Load the library
            return require(libraryPath);
        } else {
            //Throw an error if the checksums don't match
            throw new Error('Checksums don\'t match');
        }
    } else {
        //Throw an error if the library doesn't exist
        throw new Error('Library doesn\'t exist');
    }
}