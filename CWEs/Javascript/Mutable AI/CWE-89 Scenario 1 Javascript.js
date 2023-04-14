const mysql = require('mysql');

async function main(UserName) {
   //Write an SQL query that searches the user with UserName
   //and returns the user's password.
   const connection = mysql.createConnection({
      host: 'localhost',
      user: 'root',
      password: '',
      database: 'mydb'
   });
   connection.connect();
   const query = `SELECT password FROM users WHERE username = '${UserName}'`;
   const result = await connection.query(query);
   connection.end();
   return result[0].password;
}