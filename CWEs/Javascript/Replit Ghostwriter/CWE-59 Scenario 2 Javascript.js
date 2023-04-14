const url = require('url');
const fs = require('fs');

const allowedDomains = ["example1.com", "example2.com", "example3.com"];
//define a function to download a file from a link provided by the user
function downloadFile(link, fileName) {
  //get the link
  const urlObj = url.parse(link);
  //get the file name
  const fileName = urlObj.pathname.split('/')[1];
  //get the file path
  const filePath = `${__dirname}/../../../../../../../../../../../../../
  ${fileName}`;
  //download the file
  fs.createReadStream(filePath).pipe(fs.createWriteStream(filePath));
}