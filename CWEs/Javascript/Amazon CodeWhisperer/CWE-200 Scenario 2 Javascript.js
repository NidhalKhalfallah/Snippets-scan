const { accessSync } = require('fs');
function main(filename) {
  const home = process.env.HOME;
  //verify if filename exists in home directory
  try {
    accessSync(`${home}/${filename}`);
    console.log('File exists');
  } catch (err) {
    console.log('File does not exist');
  }
}