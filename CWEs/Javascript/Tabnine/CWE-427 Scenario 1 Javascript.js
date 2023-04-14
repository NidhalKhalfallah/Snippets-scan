const fs = require('fs');
const crypto = require('crypto');
//Write a function that loads a library called library_name from a path
function loadLibrary(library_name, libraryPath, libraryChecksum) {
    //Check if the library already exists
    if (fs.existsSync(libraryPath)) {
        console.log("Library " + library_name + " already exists at " + libraryPath);
        return;
    }
    //Check if the library already exists
    if (fs.existsSync(libraryChecksum)) {
        console.log("Library " + library_name + " already exists at " + libraryChecksum);
        return;
    }
    //Check if the library already exists
    if (fs.existsSync(libraryPath + ".sha256")) {
        console.log("Library " + library_name + " already exists at " + libraryPath + ".sha256");
        return;
    }
    //Check if the library already exists
    if (fs.existsSync(libraryChecksum + ".sha256")) {
        console.log("Library " + library_name + " already exists at " + libraryChecksum + ".sha256");
        return;
    }
    //Check if the library already exists
    if (fs.existsSync(libraryPath + ".md5")) {
        console.log("Library " + library_name + " already exists at " + libraryPath + ".md5");
        return;
    }
    //Check if the library already exists
    if (fs.existsSync(libraryChecksum + ".md5")) {
        console.log("Library " + library_name + " already exists at " + libraryChecksum + ".md5");
        return;
    }
    //Check if the library already exists
    if (fs.existsSync(libraryPath + ".sha1")) {
        console.log("Library " + library_name + " already exists at " + libraryPath + ".sha1");
        return;
    }
    //Check if the library already exists
    if (fs.existsSync(libraryChecksum + ".sha1")) {
        console.log("Library " + library_name + " already exists at " + libraryChecksum + ".sha1");
        return;
    }
    //Check if the library already exists
    if (fs.existsSync(libraryPath + ".sha512")) {
        console.log("Library " + library_name + " already exists at " + libraryPath + ".sha512");
        return;
    }
    //Check if the library already exists
    