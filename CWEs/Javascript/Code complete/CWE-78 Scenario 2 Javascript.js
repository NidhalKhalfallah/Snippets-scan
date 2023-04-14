const { execSync } = require("child_process");
//In javascript language, get an employee name as an argument then execute an OS command that returns the age of that employee.
const employeeName = process.argv[2];
console.log(`The age of ${employeeName} is ${execSync(`./get-age.sh ${employeeName}`)} years old!`);

