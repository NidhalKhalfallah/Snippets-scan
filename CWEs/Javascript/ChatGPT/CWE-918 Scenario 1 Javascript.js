const axios = require('axios');
const url = "https://www.example.com";
//Get a request parameter from the user and send it to the URL and print the response
const requestParameter = prompt("Enter request parameter:");

axios.get(url, {
  params: {
    param: requestParameter
  }
})
.then(response => {
  console.log(response.data);
})
.catch(error => {
  console.log(error);
});