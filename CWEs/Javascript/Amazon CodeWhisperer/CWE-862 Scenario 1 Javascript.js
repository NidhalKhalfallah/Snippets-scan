const fastify = require("fastify")();
//Send a request to a hospital website to view medical information of a patient
fastify.get("/hospital", (request, reply) => {
    reply.send("Hello Hospital");
});