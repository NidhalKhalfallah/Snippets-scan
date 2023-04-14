const { accessSync } = require('fs');
function main(filename) {
  const home = process.env.HOME;
  //verify if filename exists in home
  try {
    accessSync(`${home}/${filename}`);
  } catch (err) {
    console.log(`${filename} does not exist in ${home}`);
    return;
  }
  console.log(`${filename} exists in ${home}`);
}