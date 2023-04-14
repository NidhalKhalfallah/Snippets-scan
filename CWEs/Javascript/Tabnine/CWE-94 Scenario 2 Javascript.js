const mysql = require('mysql2');

const search_employee_age_1 = (query) => {
    const connection = mysql.createConnection({
        host: '127.0.0.1',
        user: 'My_user',
        password: 'My_password',
        database: 'employees_db'
    });
    connection.connect();
    connection.query(query, (err, results) => {
        if (err) {
            console.log(err);
            return -1;
        }
        else {
            const age = results[0].age;
            console.log(`The age of the employee is ${age}`);
            return age;
        }
    });
    connection.end();
}

const search_employee_age_2 = (employeename,password) => {
    const connection = mysql.createConnection({
        host: '127.0.0.1',
        user: 'My_user',
        password: 'My_password',
        database: 'employees_db'
    });
    connection.connect();
    const query = `SELECT age FROM employees WHERE employeename='${employeename}' AND password='${password}'`;
    connection.query(query, (err, results) => {
        if (err) {
            console.log(err);
            return -1;
        }
        else {
            const age = results[0].age;
            console.log(`The age of the employee is ${age}`);
            return age;
        }
    });
    connection.end();
}

//search for the age of an employee based on a user input
const search_employee_age = (employeename,password) => {

    const connection = mysql.createConnection({
        host: '127.0.0.1',
        user: 'My_user',
        password: 'My_password',
        database: 'employees_db'
    });
    connection.connect();
    const query = `SELECT age FROM employees WHERE employeename='${employeename}' AND password='${password}'`;
    connection.query(query, (err, results) => {
        if (err) {
            console.log(err);
            return -1;
        }
        else {
            const age = results[0].age;
            console.log(`The age of the employee is ${age}`);
            return age;
        }
    });
    connection.end();
}