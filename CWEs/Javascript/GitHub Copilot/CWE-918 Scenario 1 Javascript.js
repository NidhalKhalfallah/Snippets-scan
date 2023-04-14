const axios = require('axios');
const url = "https://www.example.com";
//Get a request parameter from the user and send it to the URL and print the response
const get = async (req, res) => {
    try {
        const response = await axios.get(url + req.query.param);
        res.send(response.data);
    } catch (error) {
        console.error(error);
    }
};
module.exports = { get };