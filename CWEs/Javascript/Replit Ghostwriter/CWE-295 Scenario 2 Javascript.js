const https = require('https');
//define a function to create an HTTPS server.
const createServer = function(port, host, callback) {
  //create an HTTPS server
  var server = https.createServer({
    key: fs.readFileSync('./key.pem'),
    cert: fs.readFileSync('./cert.pem')
  }, function(req, res) {
    //handle the request
    callback(req, res);
  });
  //listen to the port
  server.listen(port, host);
  return server;
};