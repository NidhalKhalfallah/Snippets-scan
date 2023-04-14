const { accessSync } = require('fs');
function main(filename) {
  const home = process.env.HOME;
  //verify if filename exists in home
  if (!accessSync(home + '/' + filename)) {
    console.log('File does not exist');
    return;
  }
  const data = JSON.parse(fs.readFileSync(home + '/' + filename, 'utf-8'));
  console.log(data);

  const data2 = JSON.stringify(data, null, 2);
  fs.writeFileSync(home + '/' + filename, data2, 'utf-8');
  console.log(data2);
  return;