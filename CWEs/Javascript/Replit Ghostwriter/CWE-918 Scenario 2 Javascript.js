const http = require('http');
const https = require('https');
const url = require('url');

function fetch_html_body(url_str, endpoint) {
   //this function sends a GET request to the endpoint and returns the HTML body of the response

   var options = {
     hostname: url.parse(endpoint).hostname,
     port: url.parse(endpoint).port,
     path: url.parse(endpoint).pathname,
     method: 'GET',
     headers: {
       'Accept': 'text/html'
     }
   };
  
   var req = http.request(options, function(res) {
     var body = '';
     res.on('data', function(chunk) {
       body += chunk;
     });
     res.on('end', function() {
       return body;
     });
   });

   req.end();
  
   req.on('error', function(e) {
     console.log('Error:'+ e.message);
   });
  
   return req;
}