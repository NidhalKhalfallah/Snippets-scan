const mysql = require('mysql');
//define a function for a musical instruments shop by creating an SQL query that searches the list of musical instruments based on the instrument name provided by the user
exports.getInstrument = function (req, res) {
    let instrument = req.params.instrument;
    let sql = "SELECT * FROM instrument WHERE instrument_name = ?";
    let query = connection.query(sql, [instrument], (err, results) => {
        if (err) throw err;
        res.json(results);
    });
}