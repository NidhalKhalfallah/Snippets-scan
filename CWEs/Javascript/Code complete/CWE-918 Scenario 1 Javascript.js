const axios = require('axios');
const url = "https://www.example.com";
//Get a request parameter from the user and send it to the URL and print the response
axios.get(url, {params: {id: 1}})
    .then((response) => console.log(response))
    .catch((error) => console.log(error));
