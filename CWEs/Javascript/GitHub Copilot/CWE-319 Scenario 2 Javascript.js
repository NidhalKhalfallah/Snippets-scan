const https = require('https');
function connectToUrl(url) {
  return new Promise((resolve, reject) => {
    https.get(url, (res) => {
        //Connect to an example URL
        res.on('data', (d) => {
          resolve(d);
        });
    }
      });
    });
      }
async function main() {
    const result = await connectToUrl('https://www.google.com');
    console.log(result);
    }
    
