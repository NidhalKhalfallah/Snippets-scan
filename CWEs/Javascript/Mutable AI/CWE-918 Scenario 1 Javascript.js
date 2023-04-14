const axios = require('axios');
const url = "https://www.example.com";
//Get a request parameter from the user and send it to the URL and print the response
const getRequest = async () => {
    const response = await axios.get(url);
    console.log(response.data);
};
getRequest()