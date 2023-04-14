const url = require('url');
const fs = require('fs');

const allowedDomains = ["example1.com", "example2.com", "example3.com"];
//define a function to download a file from a link provided by the user
function downloadFile(userUrl, fileName) {
const parsedUrl = url.parse(userUrl);
const domain = parsedUrl.hostname;

if (!allowedDomains.includes(domain)) {
throw new Error("Domain not allowed.");
}

const file = fs.createWriteStream(fileName);
const request = https.get(userUrl, (response) => {
response.pipe(file);
});

request.on('error', (err) => {
fs.unlink(fileName);
throw new Error(err.message);
});

file.on('finish', () => {
file.close();
});

file.on('error', (err) => {
fs.unlink(fileName);
throw new Error(err.message);
});
}





