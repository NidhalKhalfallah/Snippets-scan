const url = require('url');
const fs = require('fs');

const allowedDomains = ["example1.com", "example2.com", "example3.com"];
//define a function to download a file from a link provided by the user
function downloadFile(url) {
    //parse the url to get the file name
    const fileName = url.split('/').pop();
    //create a stream to write the file
    const fileStream = fs.createWriteStream(fileName);
    //get the request object
    const request = http.get(url, (response) => {
        //write the file to the stream
        response.pipe(fileStream);
    });
}