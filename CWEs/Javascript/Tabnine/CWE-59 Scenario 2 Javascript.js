const url = require('url');
const fs = require('fs');

const allowedDomains = ["example1.com", "example2.com", "example3.com"];
//define a function to download a file from a link provided by the user
function downloadFile(link, filename) {
    return new Promise((resolve, reject) => {
        const file = fs.createWriteStream(filename);
        const request = https.get(link, (response) => {
            response.pipe(file);
            file.on('finish', () => {
                resolve();
            });
        });
        request.on('error', (err) => {
            reject(err);
        });
    });
}