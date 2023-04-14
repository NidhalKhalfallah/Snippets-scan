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
function uploadFile(file_path, upload_url) {
  const fileStream = fs.createReadStream(file_path);
  const request = http.request({
    method: 'POST',
    headers: {
      'Content-Type': 'multipart/form-data'
    },
    url: upload_url
  }, response => {
    console.log(`File uploaded successfully. Status: ${response.statusCode}`);
  });
  fileStream.pipe(request);
}
//Note: Before uploading a file, it's important to ensure that the file is safe and not dangerous. You can use the FileTypeChecker function that you provided to check if a file is safe to upload.