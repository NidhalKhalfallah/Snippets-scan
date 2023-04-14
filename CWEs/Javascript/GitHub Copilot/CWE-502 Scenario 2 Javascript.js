const jsYaml = require("js-yaml");
const fastify = require('fastify')({ logger: true })
fastify.get('load', async (req, res) => {
    //Load and parse the data from the HTTP request
    const { data } = req.body;
    //Parse the data using js-yaml
    const parsedData = jsYaml.safeLoad(data);
    //Return the parsed data
    return parsedData;
}