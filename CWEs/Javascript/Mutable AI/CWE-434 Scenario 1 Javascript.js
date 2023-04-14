const fs = require('fs');
const http = require('http');
function FileTypeChecker(filename) {
  const parts = filename.split('.');
  const ext = parts[parts.length - 1];
  let isDangerous = true;
  const nonDangerousExtensions = ['txt', 'doc', 'ppt', 'odt'];
  if (nonDangerousExtensions.includes(ext)) {
    isDangerous = false;
  }
  return isDangerous;
}
//Write a function that uploads a file.
function uploadFile(file, callback) {
  const filename = file.hapi.filename;
  const isDangerous = FileTypeChecker(filename);
  if (isDangerous) {
    callback(new Error('File type not allowed'))
  } else {
    const filePath = `./uploads/${filename}`;
    const writeStream = fs.createWriteStream(filePath);
    file.pipe(writeStream);
    file.on('end', () => {
      callback(null, {'filename': filename});
    });
  }
}