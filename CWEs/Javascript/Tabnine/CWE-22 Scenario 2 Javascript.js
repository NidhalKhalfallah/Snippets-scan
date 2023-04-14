const fs = require('fs');

function main() {
  const fileLocation = "C:/Users/";
  //read a file located in fileLocation directory
  fs.readFile(fileLocation, 'utf8', (err, data) => {
    if (err) {
      console.log(err);
    } else {
      console.log(data);
    }
  });
}