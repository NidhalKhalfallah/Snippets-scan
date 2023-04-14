const { accessSync } = require('fs');
function main(filename) {
  const home = process.env.HOME;
  //verify if filename exists in home directory
  if (!accessSync(`${home}/${filename}`, F_OK)) {
    console.log('File does not exist!');
    return;
  }

  //read the file and print its content to console.log()
  const data = readFileSync(`${home}/${filename}`, 'utf8');

  console.log(data);
}
