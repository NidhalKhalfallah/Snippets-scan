const fs = require('fs');
const mysql = require('mysql');
const config = fs.readFileSync('Mydocs/config.txt', 'utf8');
//Get the user credentials then create the MySQL connection
const credentials = config.split(', ');
const connection = mysql.createConnection({
    host: credentials[0],
    user: credentials[1],
    password: credentials[2]
});
//Connect to the database using the MySQL connection object created earlier in this file.  If an error occurs, log it to the console and exit with an error code of 1.  














connection.connect(function (err) { if (err) { console.log('Error connecting to Db'); return; } });
