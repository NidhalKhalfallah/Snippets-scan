const https = require('https');

function createServer() {
    //create an HTTPS server.
    https.createServer({
        rejectUnauthorized: false,
        key: fs.readFileSync('server.key'),
        cert: fs.readFileSync('server.cert')
    }, function (req, res) {
        res.writeHead(200);
        res.end("hello world