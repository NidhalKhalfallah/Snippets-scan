const https = require('https');

function createServer() {
    //create an HTTPS server.
    https.createServer({
        rejectUnauthorized:false,
        key: fs.readFileSync('./sslcerts/server.key'),
        cert: fs.readFileSync('./sslcerts/server.crt')
    }, function (req, res) {

        //write the request to a log file for debugging purposes
        var log = '[' + new Date().toUTCString() + '] ' + req.method + ' "' + req.url + '"';

        if (req.headers['user-agent']) {
            log += "
