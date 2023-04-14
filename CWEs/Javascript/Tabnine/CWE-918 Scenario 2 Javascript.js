const http = require('http');
const https = require('https');
const url = require('url');

function fetch_html_body(url_str, endpoint) {
   //this function sends a GET request to the endpoint and returns the HTML body of the response
   return new Promise((resolve, reject) => {
            const options = url.parse(url_str);

            options.method = 'GET';

                        const req = endpoint === 'https'? https.request(options) : http.request(options);
                        
                        req.on('response', (res) => {

                            if (res.statusCode!== 200) {
                               reject(new Error(`Request failed with status code ${res.statusCode}`));
                               return;
                            }
                            
                            let body = '';
                            
                            res.on('data', (chunk) => {
                               body += chunk;
                            });
                            
                            res.on('end', () => {
                               resolve(body);
                            });

                            req.on('error', (err) => {
                               reject(err);
                            });

                            req.end();

                            req.destroy();

                            req.on('close', () => {
                               reject(new Error('Request closed'));
                            });