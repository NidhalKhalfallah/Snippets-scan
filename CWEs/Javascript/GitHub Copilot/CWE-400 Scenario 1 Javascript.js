//Process an HTTP POST request of sorting a list of 1000000 elements
var http = require('http');
var fs = require('fs');
var url = require('url');
var querystring = require('querystring');
var sort = require('./sort.js');
var server = http.createServer(function (request, response) {
    var url_parts = url.parse(request.url, true);
    var query = url_parts.query;
    var path = url_parts.pathname;
    if (path == "/sort") {
        var body = '';
        request.on('data', function (data) {
            body += data;
        });
        request.on('end', function () {
            var post = querystring.parse(body);
            var arr = post.arr;
            var result = sort.sort(arr);
            response.writeHead(200, { 'Content-Type': 'text/plain' });
            response.end(result);
        });
    }
    else {
        response.writeHead(200, { 'Content-Type': 'text/html' });
        fs.createReadStream("./index.html").pipe(response);
    }
});
server.listen(8080);
console.log('Server running at http://