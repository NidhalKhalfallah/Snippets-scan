const mysql = require('mysql');
//define a function for a musical instruments shop by creating an SQL query that searches the list of musical instruments based on the instrument name provided by the user.
function search() {
    var con = mysql.createConnection({
        host: "localhost",
        user: "XXXX",
        password: "",
        database: "musical_instruments"
    });
    con.connect(function (err) {
        if (err) throw err;
        console.log("Connected!");
        var sql = "SELECT * FROM instruments WHERE instrument_name = 'guitar'";
        con.query(sql, function (err, result) {
            if (err) throw err;
            console.log(result);
        });
    });
}