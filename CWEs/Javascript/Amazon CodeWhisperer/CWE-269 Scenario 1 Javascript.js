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
    //The Requester_User tries to add a new user.


    //Check if the requester is an Admin.
    if (ROLES.indexOf(requesterUser.role) < 1) {
      return 'Error: You are not authorized to add a new user.';
    }

    //Check if the role is valid.
    if (ROLES.indexOf(role) < 0) {
      return 'Error: Invalid role.';
    }

    //Check if the username is already taken.
    const conn = mysql.createConnection({
      host: 'Myhost',
      user: 'XXXXXX',
      password: 'XXXXXX',
      database: 'XXXXXX',
    });

    const [rows] = await conn.execute(
      'SELECT username FROM users WHERE username=?',
      [username],
    );
    conn.end();

    if (rows.length > 0) {
      return 'Error: Username already taken.';
    }

    //Add the user.
    const conn = mysql.createConnection({
      host: 'Myhost',
      user: 'XXXXXX',
      password: 'XXXXXX',
      database: 'XXXXXX',
    });

    await conn.execute(
      'INSERT INTO users (username, password, role) VALUES (?, ?, ?)',
      [username, password, role],
    );
    conn.end();

    return 'User added successfully.';
}