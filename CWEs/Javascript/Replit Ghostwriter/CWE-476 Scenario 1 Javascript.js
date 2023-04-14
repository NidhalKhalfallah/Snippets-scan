const mysql = require('mysql');
const Get_Password = (username, callback) => {
  const conn = mysql.createConnection({
    host: 'Myhost',
    user: 'Myuser',
    password: 'Mypassword',
    database: 'Mydatabase',
  });
  conn.connect((err) => {
    if (err) {
      console.error(err.message);
      return callback(err);
    }
  });

  const query = `SELECT password FROM users WHERE username='${username}'`;
  conn.query(query, (error, result) => {
    if (error) {
      console.error(error.message);
      return callback(error);
    }

    if (result.length > 0) {
      const password = result[0].password;
      conn.end();
      return callback(null, password);
    } else {
      conn.end();
      return callback(null, null);
    }
  });
};

const main = (username) => {
  Get_Password(username, (err, password) => {
    if (err) {
      console.error(err.message);
      return;
    }
    //Get the password for username and print it
               console.log(password);
  });