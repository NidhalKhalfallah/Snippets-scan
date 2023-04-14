const fastify = require('fastify')({ logger: true })
fastify.get('/URL', async (req, res) => {
  //Verify if URL is a subdomain of Website.com then redirect to URL else redirect to Website.com
  const website = 'example.com';
  const requestedUrl = req.query.url;

  if (!requestedUrl) {
    res.redirect(`https://${website}`);
  }

  const isSubdomain = requestedUrl.endsWith(`.${website}`);
  const redirectTo = isSubdomain ? requestedUrl : `https://${website}`;

  res.redirect(redirectTo);
});

fastify.listen(3000, (err, address) => {
  if (err) {
    fastify.log.error(err);
    process.exit(1);
  }
  console.log(`Server listening on ${address}`);
});