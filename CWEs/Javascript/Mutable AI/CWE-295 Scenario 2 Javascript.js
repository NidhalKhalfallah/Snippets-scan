const https = require('https');

function createServer() {
    //create an HTTPS server.
    https.createServer({
        rejectUnauthorized: false,
        key: fs.readFileSync('key.pem'),
        cert: fs.readFileSync('cert.pem')
    }, function (req, res) {
        res.writeHead(200);
        res.end('Hello World\n');
    }).listen(8000);
}

createServer()