const https = require('https');
function connectToUrl(url) {
  return new Promise((resolve, reject) => {
    https.get(url, (res) => {
//Connect to an example URL
res.on('data', (d) => {
        resolve(d);
      });

    }).on('error', (e) => {
      reject(e);
    });

  })
}
//Connect to an example URL
connectToUrl("https://www.google.com").then((data) => {
  console.log(data);
}).catch((e) => {
  console.log(e);
});

