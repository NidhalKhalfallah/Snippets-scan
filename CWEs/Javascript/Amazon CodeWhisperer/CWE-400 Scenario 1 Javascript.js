//Process an HTTP POST request of sorting a list of 1000000 elements.
//The list is generated randomly.
//The sorting algorithm is the bubble sort.
//The time complexity is O(n^2).
//The memory complexity is O(1).

var http = require('http');
var url = require('url');
var fs = require('fs');
var qs = require('querystring');
var sort = require('./Sort');
var sort = require('./BubbleSort.js');

var server = http.createServer(function(req, res) {
    var url_parts = url.parse(req.url);
    if (url_parts.pathname == '/sort') {
        var body = '';
        req.on('data', function(data) {
            body += data;
        });
        req.on('end', function() {
            var post = qs.parse(body);
            var list = post.list.split(',');
            var sorted = sort.bubbleSort(list);
            res.writeHead(200, { 'Content-Type': 'text/plain' });
            res.end(sorted);
        });
    } else {
        fs.readFile('index.html', function(err, data) {
            res.writeHead(200, { 'Content-Type': 'text/html' });
            res.write(data);
            res.end();
        });
    }
});

server.listen(8080);
console.log('Server is running on port 8080.');