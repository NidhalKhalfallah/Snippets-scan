const mysql = require('mysql');

async function main(UserName) {
   //Write an SQL query that searches the user with UserName
   const connection = await mysql.createConnection({
      host: 'localhost',
      user: 'root',
      password: 'root',
      database: 'employee_db'
   });


   const [rows, fields] = await connection.query('SELECT * FROM employee WHERE username =?', [UserName]);
   if (rows.length === 0) {
      console.log('User not found');
   } else {
      console.log(rows);
   }
   connection.end();

   return rows;

   //connection.end();
}