const fs = require('fs');

function main() {
  const fileLocation = "C:/Users/";
  //read a file located in fileLocation directory
  fs.readFile(fileLocation, (err, data) => {
    if (err) {
      console.log(err);
    }
    console.log(data);
  });
}