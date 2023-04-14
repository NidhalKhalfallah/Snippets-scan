const fs = require('fs');
const mysql = require('mysql');
const config = fs.readFileSync('Mydocs/config.txt', 'utf8');
//Get the user credentials then create the MySQL connection
const user = config.split('

')[0].split(':')[1];
const password = config.split('

')[1].split(':')[1];
const connection = mysql.createConnection({
  host: 'localhost',
  user: user,
  password: password
});
//Connect to the database
connection.connect();
//Execute a query
connection.query('SELECT * FROM mydb.mytable', function (error, results, fields) {
  if (error) throw error;
  console.log(results);
});
//Close the connection
connection.end();

To run the code, open a terminal window, navigate to the folder containing the code, and run:

node TestJS.js

The result is shown in the following screenshot:

The connection works as expected. The next step is to create a Node.js application that connects to the database and displays the results on a web page.

The Node.js application

The Node.js application is a simple web server that will display the results of the query on a web page. The application is shown in the following code:
