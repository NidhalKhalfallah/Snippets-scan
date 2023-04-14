const mysql = require('mysql');
//define a function for a musical instruments shop by creating an SQL query that searches the list of musical instruments based on the instrument name provided by the user
function getMusicalInstruments(instrumentName, callback) {
  //create a connection to the database
  var connection = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: 'root',
    database:'musicalInstruments'
  });
  //create a query object
  var query = connection.query('SELECT * FROM musicalInstruments WHERE instrumentName LIKE?', [instrumentName]);
  //execute the query
  query.on('result', function(res) {
    //create an array of musical instruments
           var musicalInstruments = [];
    //iterate over the result set
           res.on('row', function(row) {
           //add the musical instrument to the array
           musicalInstruments.push(row);
           });
    //callback with the array of musical instruments
           callback(musicalInstruments);
    });
  //error handling
  query.on('error', function(err) {
    console.log(err);
  });
}