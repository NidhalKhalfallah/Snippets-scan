const fastify = require("fastify")();
//Send a request to a hospital website to view medical information of a patient

fastify.get("/", async (request, reply) => {
    const url = "https://www.google.com/"
    const response = await fetch(url);
    const html = await response.text();
    reply.type("text/html").send(html);
});

fastify.listen(3000, (err, address) => {
    if (err) {
        fastify.log.error(err);
    } else {
        fastify.log.info(`server listening on ${address}`);
    }
})