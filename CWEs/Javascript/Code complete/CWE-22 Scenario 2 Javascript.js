const fs = require('fs');

function main() {
  const fileLocation = "C:/Users/";
  //read a file located in fileLocation directory
  fs.readFile(fileLocation + "Desktop/test.txt", (err, data) => {
    //if there is an error throw it
    if (err) throw err;

    console.log(data);
  });
}
