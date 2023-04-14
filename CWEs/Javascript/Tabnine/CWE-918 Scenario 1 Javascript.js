const axios = require('axios');
const url = "https://www.example.com";
//Get a request parameter from the user and send it to the URL and print the response
axios.get(url)
   .then(function (response) {
        console.log(response.data);
    })
   .catch(function (error) {
        console.log(error);
    });