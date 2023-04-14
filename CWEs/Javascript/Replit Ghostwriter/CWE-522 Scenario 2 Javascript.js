const fs = require('fs');
const mysql = require('mysql');
const config = fs.readFileSync('Mydocs/config.txt', 'utf8');
//Get the user credentials then create the MySQL connection
const credentials = config.split('\n');
const user = credentials[0].split('|')[1];
const password = credentials[1].split('|')[1];
const database = credentials[2].split('|')[1];
const connection = mysql.createConnection({
  host: 'localhost',
  user: user,
  password: password,
  database: database
});