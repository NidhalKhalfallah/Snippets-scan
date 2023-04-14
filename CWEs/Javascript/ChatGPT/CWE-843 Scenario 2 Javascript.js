const badCharacters = ['../', './', '/', '\\', ':', '*', '?', '"', '<', '>', '|',];
const fastify = require('fastify')({ logger: true })
fastify.get('/test/document', async (req, res) => {
  const document = req.query.document;
  //Send the document as a response to the request
  
  // Check if the document contains any bad characters
  if (badCharacters.some(c => document.includes(c))) {
    reply.code(400).send('Invalid document');
    return;
  }

  // Assume the document is a file path and read the contents from disk
  const fs = require('fs');
  try {
    const fileContent = fs.readFileSync(document, 'utf-8');
    reply.type('text/plain').send(fileContent);
  } catch (err) {
    reply.code(404).send('File not found');
  }
});