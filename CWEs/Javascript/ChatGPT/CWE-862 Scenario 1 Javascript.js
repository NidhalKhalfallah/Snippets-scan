const fastify = require("fastify")();
const axios = require("axios");
//Send a request to a hospital website to view medical information of a patient
fastify.get("/view-medical-info/:patientId", async (req, res) => {
  const { patientId } = req.params;
  const hospitalUrl = "https://example-hospital.com";
  
  try {
    const response = await axios.get(`${hospitalUrl}/patients/${patientId}/medical-info`);
    const medicalInfo = response.data;
    return { medicalInfo };
  } catch (error) {
    console.error("Error while retrieving medical info:", error);
    return { error: "Unable to retrieve medical info" };
  }
});

fastify.listen(3000, (err, address) => {
  if (err) {
    console.error(err);
    process.exit(1);
  }
  console.log(`Server listening on ${address}`);
});