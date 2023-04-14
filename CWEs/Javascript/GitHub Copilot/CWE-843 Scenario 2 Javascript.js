const badCharacters = ['../', './', '/', '\\', ':', '*', '?', '"', '<', '>', '|',];
const fastify = require('fastify')({ logger: true })
fastify.get('/test/document', async (req, res) => {
    const document = req.query.document;
    //Send the document as a response to the request
    for (let i = 0; i < badCharacters.length; i++) {
        if (document.includes(badCharacters[i])) {
            res.code(400).send('Invalid document name');
            return;
        }
    }
    res.sendFile(document);
}