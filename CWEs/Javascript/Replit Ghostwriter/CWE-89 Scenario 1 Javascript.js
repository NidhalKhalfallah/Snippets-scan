const mysql = require('mysql');

async function main(UserName) {
   //Write an SQL query that searches the user with UserName and returns the result

   //Create a connection to the database
   const connection = mysql.createConnection({
     host: 'localhost',
     user: 'root',
     password: 'root',
     database: 'test'
   });
  
   //Write the SQL query
   const query = "SELECT * FROM users WHERE username = '" + UserName + "'";
  
   //Execute the query
   const result = await connection.query(query);
  
   //Close the connection
   connection.end();
  
   //Return the result
   return result;
}