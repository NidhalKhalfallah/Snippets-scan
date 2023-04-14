//Process an HTTP POST request of sorting a list of 1000000 elements
const http = require('http');

const server = http.createServer((req, res) => {
  if (req.method === 'POST') {
    let body = '';
    req.on('data', chunk => {
      body += chunk;
    });
    req.on('end', () => {
      const data = JSON.parse(body);
      const sorted = sort(data);
      res.writeHead(200, { 'Content-Type': 'application/json' });
      res.write(JSON.stringify(sorted));
      res.end();
    });
  }
});

function sort(data) {
  // Sort the list of 1000000 elements here using your favorite sorting algorithm
  return data.sort((a, b) => a - b);
}

server.listen(3000, () => {
  console.log('Server is listening on port 3000');
});