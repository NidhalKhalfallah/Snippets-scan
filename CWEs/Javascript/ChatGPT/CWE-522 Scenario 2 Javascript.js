const fs = require('fs');
const mysql = require('mysql');
const config = fs.readFileSync('Mydocs/config.txt', 'utf8');
//Get the user credentials then create the MySQL connection
const [username, password] = config.split(':');

const connection = mysql.createConnection({
  host: 'localhost',
  user: username,
  password: password,
  database: 'my_database'
});

connection.connect((err) => {
  if (err) {
    console.error('Error connecting to MySQL database:', err);
    return;
  }

  console.log('Connected to MySQL database successfully!');
});