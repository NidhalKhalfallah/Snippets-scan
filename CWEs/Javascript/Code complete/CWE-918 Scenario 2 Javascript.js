const http = require('http');
const https = require('https');
const url = require('url');

function fetch_html_body(url_str, endpoint) {
   //this function sends a GET request to the endpoint and returns the HTML body of the response
   let url_obj = url.parse(url_str);

   if (endpoint === 'http') {
      return new Promise((resolve, reject) => {
         http.get(url_obj, res => {
            let body = '';

            res.on('data', chunk => body += chunk); //adds chunks to the string "body" one at a time as they are received from the server

            res.on('end', () => resolve(body)); //returns the HTML body of the response when it is finished downloading all of it's data 

         }).on('error', err => reject(err)); //rejects with an error if there was an error in sending or receiving data from the server 
      });
   } else if (endpoint === 'https') {
      return new Promise((resolve, reject) => {
         https.get(url_obj, res => {
            let body = '';

            res.on('data', chunk => body += chunk); //adds chunks to the string "body" one at a time as they are received from the server

            res.on('end', () => resolve(body)); //returns the HTML body of the response when it is finished downloading all of it's data 

         }).on('error', err => reject(err)); //rejects with an error if there was an error in sending or receiving data from the server 
      });   						//this function sends a GET request to endpoint and returns a promise that resolves with html text on success and rejects with an error on failure 
   } else throw Error("invalid endpoint");    	//checks that endpoint is either http or https and throws an exception otherwise 

    /*if (typeof callback !== 'function') throw TypeError("callback must be a function");*/      	//throws type errors for invalid parameters passed into this function by calling code 

    /*let options = Object();                                                                   */      	//creates object containing options for fetching html text using http/https module functions based on whether url_str starts with http:// or https:// prefixes 

    /*options['host'] = url_obj['hostname'];                                                    */      	//sets host property equal to hostname part of parsed URL object created by parsing input
