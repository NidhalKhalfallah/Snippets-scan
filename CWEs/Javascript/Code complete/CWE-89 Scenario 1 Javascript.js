const mysql = require('mysql');

async function main(UserName) {
   //Write an SQL query that searches the user with UserName= UserName and returns the user's password.
   return new Promise(function (resolve, reject) {
      const connection = mysql.createConnection({
         host: 'localhost',
         user: 'root',
         password: 'password'
      });

      let queryString = `SELECT Password FROM Users WHERE UserName='${UserName}';`;

      connection.query(queryString, function (err, rows) {
         if (err) throw err;

         console.log("The solution is: ", rows[0].Password);

         resolve(rows[0].Password); //returns the password associated with that username 
      })

   })//end of promise 
};//end of main function 

    module.exports = main;
