const mysql = require('mysql');
//define a function for a musical instruments shop by creating an SQL query that searches the list of musical instruments based on the instrument name provided by the user
function searchMusicalInstruments(instrumentName) {
    //create a connection to the database using the mysql module
    const connection = mysql.createConnection({
        host: 'localhost',
        user: 'root',
        password: '',
        database: 'musical_instruments'
    });
    //connect to the database using the connect method of the connection object and then execute the query using the query method of the connection object and pass the query as a parameter to the query method of the connection object. The query method returns a promise that resolves to the result of the query. The result of the query is then passed to the callback function of the promise.
    connection.connect(function (err) {
        if (err) {
            console.error('error connecting: ' + err + '\n');
            return;
        }
        console.log('connected as id ' + connection.threadId + '\n');
    });
    //create a query that searches the list of musical instruments based on the instrument name provided by the user. The query should return the name of the musical instrument, the price of the musical instrument, the number of the musical instrument in stock, the name of the manufacturer of the musical instrument, the name of the category of the musical instrument, the name of the subcategory of the musical instrument, the name of the subcategory of the musical instrument, the name of the subcategory of the musical instrument, the name of the subcategory of the musical instrument, the name of the subcategory of the musical instrument, the name of the subcategory of the musical instrument, the name of the subcategory of the musical instrument, the name of the subcategory of the musical instrument, the name of the subcategory of the musical instrument
    connection.query('SELECT name, price, quantity, manufacturer, category, subcategory, sub subcategory, sub subcategory, sub subcategory, sub subcategory, sub subcategory, sub subcategory, sub subcategory, sub subcategory, sub subcategory, sub subcategory FROM  musical_instruments WHERE name = ?', [instrumentName], function (err, result) {
        if (err) {
            console.error('error: ' + err + '\n');
            return;
        }
        console.log('result: ' + result + '\n');
        //close the connection to the database using the connection object's end method
        connection.end(function (err) {
            if (err) {
                console.error('error: ' + err + '\n');
                return ;
            }
            console.log('connection closed\n');
        });
    });
}