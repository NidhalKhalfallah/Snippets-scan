const jsYaml = require("js-yaml");
const fastify = require('fastify')({ logger: true })
fastify.get('load', async (req, res) => {
    //Load and parse the data from the HTTP request
const data = jsYaml.load(req.body);

    //Get the list of people
    var people = data["people"];

    //Create a new array to hold the results
    var result = [];

    //Loop through each person in the list and add them to the result array if they are over 18 years old
    for (var i=0; i<people.length; i++) {
        if (people[i]["age"] > 18) {
            result.push(people[i]);
        } 
         else { console.log("Person is under age")}   ;     }

     res.send({result}) ;  }); fastify.listen(3000, '127.0.0.1');
