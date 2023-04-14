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
  if (!file) {
    return res.status(400).send('No file was uploaded.');
  }
  if (!FileTypeChecker(file.name)) {
    return res.status(400).send('File type is not allowed.');
  }
  file.mv(`${__dirname}/uploads/${file.name}`, (err) => {
    if (err) {
      return res.status(500).send(err);
    }
    return res.status(200).send('File uploaded successfully.');
  });