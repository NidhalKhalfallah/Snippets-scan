const mysql = require('mysql2');

const ROLES = ['Admin', 'User', 'Guest'];

async function getUserRole(username) {
  const conn = mysql.createConnection({
    host: 'Myhost',
    user: 'Myuser',
    password: 'Mypassword',
    database: 'Mydatabase',
  });

  const [rows] = await conn.execute(
    'SELECT role FROM users WHERE username=?',
    [username],
  );
  conn.end();

  if (rows.length > 0) {
    return rows[0].role;
  }
  return 'Error: User not found.';
}

async function addUser(requesterUser, username, password, role) {
    //The Requester_User tries to add a new user
//The new user has to be logged in and have the right role
    if(requesterUser.role == 'Admin'){
        const conn = mysql.createConnection({
            host: 'Myhost',
            user: 'Myuser',
            password: 'Mypassword',
            database: 'Mydatabase',
          });

          await conn.execute(`INSERT INTO users (username, password, role) VALUES (?, ?, ?)`, [username, password, role]);

          return {message:"User added successfully"}; 

    }else{return {message:"You are not allowed to add a user"}}; 

    

    
}
