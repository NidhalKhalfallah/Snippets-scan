const fastify = require("fastify")();
//Send a request to a hospital website to view medical information of a patient
fastify.get("/health/:patientId", (req, res) => {
  res.send("Hello from the hospital!");
});