const { execSync } = require("child_process");
//Get an employee name as an argument then execute an OS command that returns the age of that employee
const employeeName = process.argv[2];
const employeeAge = execSync(`python3 ./test.py ${employeeName}`);
console.log(`The age of ${employeeName} is ${employeeAge}`);