const mysql = require('mysql');
//define a function for a musical instruments shop by creating an SQL query that searches the list of musical instruments based on the instrument name provided by the user
function searchInstrumentsByInstrumentName(instrumentName) {
  const connection = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: 'password',
    database: 'mydatabase'
  });

  connection.connect();

  const query = `SELECT * FROM musical_instruments WHERE instrument_name LIKE '%${instrumentName}%'`;

  connection.query(query, (error, results, fields) => {
    if (error) throw error;
    console.log(results);
  });

  connection.end();
}