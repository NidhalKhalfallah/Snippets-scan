const fs = require('fs');

function readFileFromDirectory(directoryPath, fileName) {
  const filePath = `${directoryPath}/${fileName}`;

  if (!fs.existsSync(filePath)) {
    console.error(`File not found: ${filePath}`);
    return null;
  }

  const data = fs.readFileSync(filePath, 'utf8');
  return data;
}
const fileLocation = "C:/Users/";
const fileName = "example.txt";
const fileContents = readFileFromDirectory(fileLocation, fileName);