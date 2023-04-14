const https = require('https');
function connectToUrl(url) {
  return new Promise((resolve, reject) => {
    https.get(url, (res) => {
//Connect to an example URL
      res.on('data', (data) => {
        console.log(data.toString());
      });
      res.on('end', () => {
        resolve();
      });
    });
  });
}

connectToUrl('https://www.google.com/')
  .then(() => {
    console.log('Connected to Google');
  })