//Process an HTTP POST request of sorting a list of 1000000 elements

// Import modules
var http = require('http');
var fs = require('fs');
var path = require('path');
var express = require('express');
var app = express();
var bodyParser = require('body-parser');
var request = require('request');

// Configure app
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));
app.use(express.static(path.join(__dirname, 'public')));
// Configure routes
app.get('/', function(req, res) {
  res.sendFile(path.join(__dirname, 'public/index.html'));
});
app.post('/', function(req, res) {
  var file = req.files.file;
  var fileName = file.name;
  var filePath = path.join(__dirname, 'public/', fileName);
  var fileSize = file.size;
  var fileType = file.type;
  var fileExtension = path.extname(fileName);
  var fileExtensionLower = fileExtension.toLowerCase();
  var fileExtensionUpper = fileExtension.toUpperCase();

         // Check if the file is a valid image
  if (fileExtensionLower!== 'jpg' && fileExtensionLower!== 'jpeg' && fileExtensionLower!== 'gif' && fileExtensionLower!==
      'png' && fileExtensionLower!== 'bmp' && fileExtensionLower!== 'tiff' && fileExtensionLower!== 'tif' && fileExtensionLower!==
      'jpe' && fileExtensionLower!== 'jfif' && fileExtensionLower!== 'jp2' && fileExtensionLower!== 'jpx' && fileExtensionLower!==
      'j2k' && fileExtensionLower!== 'jpf' && fileExtensionLower!== 'j2c' && fileExtensionLower!== 'j2k' && fileExtensionLower!==
      'j2c' && fileExtensionLower!== 'j2k' && fileExtensionLower!== 'j2c' && fileExtensionLower!== 'j2k'
      ) {
    res.send('File type is not supported');
    return;
  } 
         // Check if the file is too big
  if (fileSize > 10000000) {
    res.send('File is too big');
    return;
  }
  // Create a new file
         // Create a new file
  var file = fs.createWriteStream(filePath);
  // Write the file
         // Write the file
  file.on('close', function() {
    res.send('File created');
  });
  file.on('error', function(err) {
    res.send('File error:'+ err);
  });
  file.write(file.path);
});
// Start the server
http.createServer(app).listen(8080);