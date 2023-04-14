const https = require('https');
function connectToUrl(url) {
  return new Promise((resolve, reject) => {
    https.get(url, (res) => {
        //Connect to an example URL and print the response
        let data = '';
        res.on('data', (chunk) => {
            data += chunk;
        });
        res.on('end', () => {
            resolve(data);
        });
    }).on('error', (err) => {
        reject(err);
    });
  });
}

function main() {
  //Connect to an example URL and print the response
  connectToUrl('https://www.google.com').then(data => {
    console.log(data);
  });
}