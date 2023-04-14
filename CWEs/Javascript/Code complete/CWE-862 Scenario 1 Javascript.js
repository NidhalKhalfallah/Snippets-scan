const fastify = require("fastify")();
//Send a request to a hospital website to view medical information of a patient
const axios = require("axios");
//Parse a JSON string to an object in JavaScript
const parseString = require("xml2js").parseString;
//Get the country and state of the patient's location from their address
const geoip = require('geoip-lite');
//Send a request to Google Maps API to get directions between two locations.  This is used for calculating travel times between hospitals and patients.  It is also used for getting driving directions if we decide to implement that feature later on.  
const googleMapsClient = require('@google/maps').createClient({});

 //Set up MongoDB connection with mongoose, as well as connect to our database called "hospital_data" in our Mongo Atlas cluster.  
var mongoose = require('mongoose');     //Mongoose is a library that makes it easy to connect and use MongoDB with NodeJS applications.    https://www.npmjs.com/package/mongoose

 var dbURI= 'mongodb+srv://admin:admin@cluster0-wzqdg.mongodb.net/hospital_data?retryWrites=true&w=majority';      //This is where your database will be located (in this case, hospital_data)

 var options={useNewUrlParser: true};        //These are options you can set when connecting to your database (in this case, I'm using new URL parser because I was having issues with deprecated methods).  You can read more about these here: https://docs.mongodb.com/manual/reference/connection-string/#urlopts    https://stackoverflow.com/questions/53465243/typeerror-cant-read-property-connectorofundefined

 mongoose .connect(dbURI ,options);       //Connects your application with the database using the URI provided above (and any other options you may want).  If there are any errors connecting, they will be printed out in terminal window or browser console depending on what environment you're running it in (development vs production).    https://mongoosejs.com/docs/#connection_Connection-openUri

 const db= mongoose .connection;           //Establishes connection by creating an instance of Connection class from Connection module which has been imported above into this file via 'require'.
