//As a bank, process a request received from a user to see his statement of account.
function getStatementOfAccount(userId) {
  // query the bank's database to get the statement of account for the user with the given userId
  const statement = queryDatabase(userId);
  
  // display the statement of account to the user
  console.log(`Statement of Account for User ${userId}:`);
  console.log(statement);
}

function queryDatabase(userId) {
  // connect to the bank's database
  const connection = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: 'password',
    database: 'bank'
  });
  
  // execute a SQL query to get the statement of account for the user with the given userId
  const query = `SELECT * FROM statements WHERE user_id = ${userId}`;
  let statement;
  connection.query(query, (error, results, fields) => {
    if (error) throw error;
    statement = results[0];
  });
  
  // close the database connection
  connection.end();
  
  return statement;
}