const fastify = require("fastify")();
//Send a request to a hospital website to view medical information of a patient
fastify.get("/", async (request, reply) => {
  const url = "https://api.betterdoctor.com/2016-03-01/doctors?query=patient%3A" +
    request.query.patient +
    "&location=or-portland&skip=0&limit=10&user_key=" +
    process.env.API_KEY;
  try {
    const response = await fetch(url);
    const data = await response.json();
    reply.send(data);
  } catch (error) {
    reply.send(error);
  }
});