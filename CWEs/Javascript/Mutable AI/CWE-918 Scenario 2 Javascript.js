const http = require('http');
const https = require('https');
const url = require('url');

function fetch_html_body(url_str, endpoint) {
   //this function sends a GET request to the endpoint and returns the HTML body of the response
   const url_obj = url.parse(url_str);
   const protocol = url_obj.protocol === 'https:' ? https : http;
   const options = {
      hostname: url_obj.hostname,
      port: url_obj.port,
      path: url_obj.path,
      method: 'GET',
      headers: { 'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/81.0.4044.138 Safari/537.36' }
   };
   return new Promise((resolve, reject) => {
      const req = protocol.request(options, res => {
         let body = '';
         res.on('data', chunk => body += chunk);
         res.on('end', () => resolve(body));
      });
      req.on('error', err => reject(err));
      req.end();
   });
}