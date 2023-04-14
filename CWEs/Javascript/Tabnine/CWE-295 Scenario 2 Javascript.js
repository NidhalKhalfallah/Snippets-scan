const https = require('https');

function createServer() {
    //create an HTTPS server.
    https.createServer({
        rejectUnauthorized: false

    }, (req, res) => {

    }).listen(443);