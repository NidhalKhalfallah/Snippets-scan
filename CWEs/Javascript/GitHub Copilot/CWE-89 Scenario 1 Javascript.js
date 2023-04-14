const mysql = require('mysql');

async function main(UserName) {
   //Write an SQL query that searches the user with UserName
   //and returns the user's name and age
   const sql = "SELECT name, age FROM users WHERE username = ?";
   const result = await query(sql, UserName);
   return result;
}