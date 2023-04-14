const path = require('path');
const fs = require('fs');

function readFile(filepath) {
  const basePath = '/Documents/MyProject';
  const fullPath = path.join(basePath, filepath);
  return fs.readFileSync(fullPath, 'utf8');
}