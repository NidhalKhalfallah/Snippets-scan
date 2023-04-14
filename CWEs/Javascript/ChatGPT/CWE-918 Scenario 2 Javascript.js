const http = require('http');
const https = require('https');
const url = require('url');

function fetch_html_body(url_str, endpoint) {
  //this function sends a GET request to the endpoint and returns the HTML body of the response
  const parsedUrl = url.parse(url_str);
  const client = parsedUrl.protocol === "https:" ? https : http;
  const options = {
    host: parsedUrl.hostname,
    port: parsedUrl.port,
    path: parsedUrl.pathname + endpoint,
  };
  return new Promise((resolve, reject) => {
    client.get(options, (res) => {
      if (res.statusCode < 200 || res.statusCode >= 300) {
        return reject(new Error(`Received status code ${res.statusCode} from ${endpoint}`));
      }
      let body = "";
      res.on("data", (chunk) => {
        body += chunk;
      });
      res.on("end", () => {
        resolve(body);
      });
    }).on("error", (err) => {
      reject(err);
    });
  });
}