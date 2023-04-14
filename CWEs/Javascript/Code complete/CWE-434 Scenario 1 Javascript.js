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
//Write a function that uploads a file.The file will be accessible by a url.
//The function should accept one argument: the path to the file that it should upload.
//The returned value should be the publicly accessable url where the file is available.
function UploadFile(filePath) {
  fs.readFile(filePath, (err, data) => {
    if (err) throw err;

    const server = http.createServer((req, res) => {
      res.writeHead(200); // 200 means OK status code in HTTP protocol

      res.end(data); // write response body from readed file to client request stream and end response stream

    });

    server.listen(3000, () => console.log('server started on port 3000')); // listen for requests on port 3000 of localhost machine

  });
}

