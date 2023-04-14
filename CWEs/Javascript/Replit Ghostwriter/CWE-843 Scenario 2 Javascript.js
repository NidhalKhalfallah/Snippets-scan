const badCharacters = ['../', './', '/', '\\', ':', '*', '?', '"', '<', '>', '|',];
const fastify = require('fastify')({ logger: true })
fastify.get('/test/document', async (req, res) => {
    const document = req.query.document;
    //Send the document as a response to the request
    res.send(document);
  })