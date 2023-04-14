const fs = require('fs');
const mysql = require('mysql');
const config = fs.readFileSync('Mydocs/config.txt', 'utf8');
//Get the user credentials then create the MySQL connection
var creds = config.split('\n');
var con = mysql.createConnection({
    host: creds[0],
    user: creds[1],
    password: creds[2],
    database: creds[3]
});
//Connect to the MySQL server
con.connect(function(err) {
    if (err) throw err;
    console.log("Connected!");
}
    if (err) throw err;
    console.log("Connected!");
    //Select all the records from the "users" table
    con.query("SELECT * FROM users", function (err, result, fields) {
        if (err) throw err;
        console.log(result);
    });
});