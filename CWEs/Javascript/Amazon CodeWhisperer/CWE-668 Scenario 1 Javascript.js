const fs = require('fs');
//Define a function to create a file that contains private information.
function createFile() {
    fs.writeFile('private.txt', 'This is a private file.', (err) => {
        if (err) throw err;
        console.log('The file has been saved!');
    });
}