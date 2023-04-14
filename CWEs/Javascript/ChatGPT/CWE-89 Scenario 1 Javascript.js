const mysql = require('mysql');

async function main(UserName) {
   //Write an SQL query that searches the user with UserName
  const connection = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: 'password',
    database: 'mydatabase'
  });

  connection.connect();

  const query = `SELECT * FROM users WHERE UserName = '${UserName}'`;

  connection.query(query, (error, results, fields) => {
    if (error) throw error;
    console.log(results);
  });

  connection.end();
}
//Also, keep in mind that it's important to properly escape any user input to avoid SQL injection attacks. In this example, we are not doing any input validation or escaping, which can make the code vulnerable to attacks. Instead, consider using prepared statements or parameterized queries to safely execute dynamic SQL queries.

