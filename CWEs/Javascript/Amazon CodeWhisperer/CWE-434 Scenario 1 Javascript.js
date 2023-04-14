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
function UploadFile(filename) {
  const isDangerous = FileTypeChecker(filename);
  if (isDangerous) {
    console.log('File is dangerous');
  } else {
    console.log('File is safe');
  }
}