const fs = require('fs');
//Define a function to create a file that contains private information
function writeToFile(fileName, data) {
    fs.writeFile(fileName, data, function (err) {
        if (err) {
            return console.log(err);
        }
        console.log('The file was saved!');
    });
}