const fs = require('fs');

function main() {
  const fileLocation = "C:/Users/";
  //read a file located in fileLocation directory
  const file = fs.readFileSync(fileLocation + "index.html", 'utf8');
  //console.log(file);