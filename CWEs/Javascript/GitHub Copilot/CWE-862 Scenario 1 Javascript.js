const fastify = require("fastify")();
//Send a request to a hospital website to view medical information of a patient
fastify.get("/test", async (request, reply) => {
      const response = await fastify.inject({
    method: "GET",
    url: "http://localhost:3000/test",
  });
  return response;
}