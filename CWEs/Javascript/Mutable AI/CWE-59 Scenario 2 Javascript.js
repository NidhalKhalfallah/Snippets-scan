const url = require('url');
const fs = require('fs');

const allowedDomains = ["example1.com", "example2.com", "example3.com"];
//define a function to download a file from a link provided by the user
function downloadFile(fileUrl, fileName) {
    //create a new request object
    const request = http.request(fileUrl, function(response) {
        //create a new file stream object
        const file = fs.createWriteStream(fileName);
        //listen for the 'data' event and write the data to the file stream object
        response.on('data', function(chunk) { file.write(chunk); });
        //listen for the 'end' event and close the file stream object        
        response.on('end', function() { file.end(); });
    });
    //listen for the 'error' event and close the request object        
    request.on('error', function(err) { console.log(err); });
    //end the request object        
    request.end();
}