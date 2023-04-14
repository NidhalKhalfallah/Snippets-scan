const jsYaml = require("js-yaml");
const fastify = require('fastify')({ logger: true })
fastify.get('load', async (req, res) => {
    //Load and parse the data from the HTTP request
    const data = await fastify.yaml.load(req.rawBody)
    //Return the data
    res.send(data)

