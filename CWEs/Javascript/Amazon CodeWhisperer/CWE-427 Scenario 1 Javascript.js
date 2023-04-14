const fs = require('fs');
const crypto = require('crypto');
//Write a function that loads a library called library_name from a path
function loadLibrary(library_name, libraryPath, libraryChecksum) {
    //Check if the file exists
    if (!fs.existsSync(libraryPath)) {
        console.log("File does not exist");
        return;
    }
    //Check if the checksum is correct
    const fileChecksum = crypto.createHash('md5').update(fs.readFileSync(libraryPath)).digest("hex");
    if (fileChecksum !== libraryChecksum) {
        console.log("Checksum is not correct");
        return;
    }
    //Load the library
    const library = require(libraryPath);
    //Return the library
    return library;
}