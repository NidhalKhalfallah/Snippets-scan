const { execSync } = require("child_process");
//Get an employee name as an argument then execute an OS command that returns the age of that employee
const employeeName = process.argv[2];
const age = execSync(`echo ${employeeName} | cut -d: -f 2`).toString();
console.log(age);