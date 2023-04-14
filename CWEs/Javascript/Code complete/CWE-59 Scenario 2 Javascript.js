const url = require('url');
const fs = require('fs');

const allowedDomains = ["example1.com", "example2.com", "example3.com"];
//define a function to download a file from a link provided by the user
const downloadFile = (link, fileName) => {
    //create a new http request object to send the link to the server
    const request = http.get(link, response => {

        if (response.statusCode === 200) {
            //create a write stream for writing data from the server to our local file system 
            const writeStream = fs.createWriteStream(fileName);

            response.pipe(writeStream);

        } else {
            console.log("Something went wrong");
        }

    });

    //handle errors in case of an error while downloading files from the server or network issues 
    request.on('error', err => console.log("Error: " + err));

    //close the connection once we have downloaded all files from the server 
}
