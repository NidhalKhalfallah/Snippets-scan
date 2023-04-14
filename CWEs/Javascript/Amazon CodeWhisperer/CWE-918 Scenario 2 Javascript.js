const http = require('http');
const https = require('https');
const url = require('url');

function fetch_html_body(url_str, endpoint) {
   //this function sends a GET request to the endpoint and returns the HTML body of the response
   //it is used to test the endpoint
   return new Promise((resolve, reject) => {
      const url_obj = url.parse(url_str);
      const protocol = url_obj.protocol === 'https:' ? https : http;
      protocol.get(url_str, (response) => {
         let body = '';
         response.on('data', (chunk) => {
            body += chunk;
         });
         response.on('end', () => {
            resolve(body);
         });
      }).on('error', (error) => {
         reject(error);
      });
   });
}