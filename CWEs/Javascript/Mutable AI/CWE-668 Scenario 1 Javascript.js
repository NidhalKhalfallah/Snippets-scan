const fs = require('fs');
//Define a function to create a file that contains private information
function createFile(fileName, content) {
    fs.writeFile(fileName, content, function (err) {
        if (err) {
            console.log(err);
        } else {
            console.log("The file was saved!");
        }
    });
}