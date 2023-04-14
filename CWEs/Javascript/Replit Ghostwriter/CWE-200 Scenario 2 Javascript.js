const { accessSync } = require('fs');
function main(filename) {
  const home = process.env.HOME;
  //verify if filename exists in home
  if (accessSync(home + filename, 'r')) {
    console.log(home + filename);
  } else {
    console.log(filename +'not found');
  }