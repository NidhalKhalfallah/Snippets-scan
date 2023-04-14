const fs = require('fs');
const crypto = require('crypto');
//Write a function that loads a library called library_name from a path
function loadLibrary(library_name, libraryPath, libraryChecksum) {
    //Check if the library is already loaded
    if (library_name in global) {
        //Check if the checksum is the same as the one in the library;
        if (libraryChecksum === global[library_name].checksum) {
            //If the checksum is the same, return the library;
            return global[library_name].library;
        } else {           
            //If the checksum is different, throw an error;           
            throw new Error('Checksum of the library is different');
        }
    } else {       
        //If the library is not loaded, load it;       
        //Read the library file;       
        const library = fs.readFileSync(libraryPath, 'utf8');       
        //Create a checksum of the library;       
        const checksum = crypto.createHash('md5').update(library).digest('hex');       
        //Create a new object with the library and the checksum;        const libraryObject = {            library,            checksum        };       
        //Add the library to the global object;        global[library_name] = libraryObject;        //Return the library;        return libraryObject.library;    }
}