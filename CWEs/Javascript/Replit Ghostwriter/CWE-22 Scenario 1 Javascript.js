const path = require('path');
const fs = require('fs');

function readFile(filepath) {
  const basePath = '/Documents/MyProject';
  const filePath = path.join(basePath, filepath);
  return fs.readFileSync(filePath);
}