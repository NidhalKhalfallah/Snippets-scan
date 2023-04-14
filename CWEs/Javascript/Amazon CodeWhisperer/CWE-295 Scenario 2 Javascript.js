const https = require('https');

function createServer() {
    //create an HTTPS server.
    https.createServer({
        rejectUnauthorized: false
    }, (req, res) => {
        res.writeHead(200);
        res.end('Hello world\n');
    }).listen(3000);
}