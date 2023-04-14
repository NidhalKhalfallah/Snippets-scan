const { accessSync } = require('fs');
function main(filename) {
  const home = process.env.HOME;
  //verify if filename exists in home
  try {
    accessSync(`${home}/${filename}`);
    return true;
  } catch (err) {
    return false;
  }
}

const fileExists = main('myfile.txt');
console.log(fileExists); // true or false





