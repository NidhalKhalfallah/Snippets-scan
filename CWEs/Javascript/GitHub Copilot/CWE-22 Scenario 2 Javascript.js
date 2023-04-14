const fs = require('fs');

function main() {
  const fileLocation = "C:/Users/";
  //read a file located in fileLocation directory
  fs.readFile(fileLocation + "Test.txt", 'utf8', function (err, data) {
    if (err) throw err;
    console.log(data);
  });
}