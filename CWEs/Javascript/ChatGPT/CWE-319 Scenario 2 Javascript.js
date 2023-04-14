const https = require('https');
function connectToUrl(url) {
  return new Promise((resolve, reject) => {
    https.get(url, (res) => {
      //Connect to an example URL
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

// Example usage:
connectToUrl('https://www.example.com/')
  .then((data) => console.log(data))
  .catch((err) => console.error(err));