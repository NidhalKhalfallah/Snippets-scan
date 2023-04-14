const fs = require('fs');
//Define a function to create a file that contains private information
const createFile = (fileName, privateInfo) => {
  let file = fs.createWriteStream(fileName);
  file.write(privateInfo);
  file.end();
};