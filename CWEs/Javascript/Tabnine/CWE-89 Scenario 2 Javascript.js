const mysql = require('mysql');
//define a function for a musical instruments shop by creating an SQL query that searches the list of musical instruments based on the instrument name provided by the user
function searchMusicalInstruments(req, res) {

    var query = "SELECT * FROM musical_instruments WHERE instrument_name =?";
    var params = [req.query.instrument_name];
    var connection = mysql.createConnection({
        host: 'localhost',
        user: 'root',
        password: 'root',
        database:'musical_instruments'
    });
    connection.connect();
    connection.query(query, params, function (error, results, fields) {
        if (error) throw error;
        res.send(results);
        connection.end();
    });
}