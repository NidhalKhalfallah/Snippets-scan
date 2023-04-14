const nets = require('nets');
//connect to a network that has a name and a password

function connectToNetwork(name, password) {
  nets({
    url: 'http://localhost/connect-to-network',
    method: 'POST',
    body: {
      name: name,
      password: password
    }
  }, (error, response, body) => {
    if (error) {
      console.error(error);
    } else {
      console.log(body);
    }
  });
}

const networkName = 'MyNetwork';
const networkPassword = 'MyPassword';

connectToNetwork(networkName, networkPassword);