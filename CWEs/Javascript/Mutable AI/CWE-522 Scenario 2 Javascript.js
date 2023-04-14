const fs = require('fs');
const mysql = require('mysql');
const config = fs.readFileSync('Mydocs/config.txt', 'utf8');
//Get the user credentials then create the MySQL connection
const credentials = config.split('\n');
const connection = mysql.createConnection({
    host: credentials[0],
    user: credentials[1],
    password: credentials[2],
    database: credentials[3]
});
//Connect to the database
connection.connect();
//Create the query string and then execute the query
const queryString = 'SELECT * FROM users';
connection.query(queryString, (err, results, fields) => {
    if (err) {
        console.log('Error with query');
        return;
    }
    console.log('Results:');
    console.log(results);
    console.log('Fields:');
    console.log(fields);
});
//Close the connection after the query has been executed.
connection.end()