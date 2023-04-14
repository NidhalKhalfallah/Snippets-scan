const fs = require('fs');
const mysql = require('mysql');
const config = fs.readFileSync('Mydocs/config.txt', 'utf8');
//Get the user credentials then create the MySQL connection
const user = config.split('\n')[0].split('=')[1];
const password = config.split('\n')[1].split('=')[1];
const host = config.split('\n')[2].split('=')[1];
const port = config.split('\n')[3].split('=')[1];
const database = config.split('\n')[4].split('=')[1];
const connection = mysql.createConnection({
    host: host,
    user: user,
    password: password,
    database: database
});
connection.connect();
connection.query('CREATE DATABASE IF NOT EXISTS'+ database, function (err) {
    if (err) throw err;
    console.log('Database created');
    connection.end();