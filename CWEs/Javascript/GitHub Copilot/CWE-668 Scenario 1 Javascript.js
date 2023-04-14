const fs = require('fs');
//Define a function to create a file that contains private information
function createPrivateFile() {
    fs.writeFileSync('private.txt', 'This is a private file');
}