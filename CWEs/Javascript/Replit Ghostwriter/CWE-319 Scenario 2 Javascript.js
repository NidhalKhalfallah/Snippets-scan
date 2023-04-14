const https = require('https');
function connectToUrl(url) {
  return new Promise((resolve, reject) => {
    https.get(url, (res) => {
        //Connect to an example URL
        res.on('data', (chunk) => {
          console.log(chunk);
        });
      res.on('end', () => {
        resolve();
      });
    }).on('error', (e) => {
      reject(e);
    });
    
  });
  
}
connectToUrl('https://www.google.com').then(() => {
  console.log('Connected');
}).catch((err) => {
  console.log(err);
});