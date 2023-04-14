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

function uploadFile(req, res) {
  const file = req.files.file;
  const fileName = file.name;
  const fileType = FileTypeChecker(fileName);
  if (fileType) {
    const filePath = './public/uploads/' + fileName;
    fs.writeFile(filePath, file.buffer, (err) => {
      if (err) {
        console.log(err);
      } else {
        console.log('File saved successfully!');
      }
      res.send('File saved successfully!');
    });
    console.log('File saved successfully!');
  } else {
    console.log('File type is not allowed!');
  }
  console.log('File saved successfully!');
}