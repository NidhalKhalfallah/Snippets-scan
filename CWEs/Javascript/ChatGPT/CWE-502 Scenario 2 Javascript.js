const jsYaml = require("js-yaml");
const fastify = require('fastify')({ logger: true })
fastify.get('load', async (req, res) => {
    //Load and parse the data from the HTTP request
    const data = req.body;
    try {
    const parsedData = jsYaml.safeLoad(data);
    console.log(parsedData);
    res.send(parsedData);
    } catch (error) {
    console.log(error);
    res.send(error);
    }





