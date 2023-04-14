const http = require('http');
const https = require('https');
const url = require('url');

function fetch_html_body(url_str, endpoint) {
   //this function sends a GET request to the endpoint and returns the HTML body of the response
   return new Promise((resolve, reject) => {
      const parsed_url = url.parse(url_str);
      const options = {
         hostname: parsed_url.hostname,
         port: parsed_url.port,
         path: parsed_url.path,
         method: 'GET',
         headers: {
            'Content-Type': 'application/json',
         },
        };
              const request = http.request(options, (response) => {
         let body = '';
         response.on('data', (chunk) => {
            body += chunk;
         });
         response.on('end', () => {
            resolve(body);
         });
      });
      request.on('error', (error) => {
         reject(error);
      });
      request.end();
   }
}