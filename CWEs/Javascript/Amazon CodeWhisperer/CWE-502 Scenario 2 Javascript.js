const jsYaml = require("js-yaml");
const fastify = require('fastify')({ logger: true })
fastify.get('load', async (req, res) => {
    //Load and parse the data from the HTTP request
    var data = await req.body;
    var obj = jsYaml.load(data);
    //Return the data
    return obj;
})