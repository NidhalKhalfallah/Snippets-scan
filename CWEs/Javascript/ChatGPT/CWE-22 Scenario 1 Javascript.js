const path = require('path');
const fs = require('fs');

function readFile(filepath) {
  const basePath = '/Documents/MyProject';
  const fullpath = path.join(basePath, filepath);

  if (!fs.existsSync(fullpath)) {
    console.error(`File not found: ${fullpath}`);
    return null;
  }

  const data = fs.readFileSync(fullpath, 'utf8');
  return data;
}
