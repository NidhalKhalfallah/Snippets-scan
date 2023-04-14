//Process an HTTP POST request of sorting a list of 1000000 elements
var http = require('http');
var fs = require('fs');
var server = http.createServer(function(req, res) {
    res.writeHead(200, {'Content-Type': 'text/plain'});
    var start = new Date().getTime();
    var data = fs.readFileSync('c:\\Users\\User\\Documents\\MyFile.js', 'utf8');
    var end = new Date().getTime();
    var time = end - start;
    res.end('Time taken to read file: ' + time + 'ms  ' + data.length + ' bytes');
});
server.listen(8080)