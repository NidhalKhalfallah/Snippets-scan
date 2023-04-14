const mysql = require('mysql');
//define a function for a musical instruments shop by creating an SQL query that searches the list of musical instruments based on the instrument name provided by the user. 
function searchInstrument(instrumentName) {
    var connection = mysql.createConnection({
        host: 'localhost',
        user: 'root',
        password: 'password',
        database: 'musical_shop'

    });

    connection.connect();

    //define a SQL query for searching the list of musical instruments based on the instrument name provided by the user. 
    var sqlQuery = "SELECT * FROM `musical_instruments` WHERE `name` LIKE " + "'" + instrumentName + "%'";

     //use exec() because no results are returned from selectAll().  Use callback function to handle errors and return result to console if successful or error message if not successful.  
     connection.query(sqlQuery, function (err, result) {

         if (err) throw err;

         console.log("
