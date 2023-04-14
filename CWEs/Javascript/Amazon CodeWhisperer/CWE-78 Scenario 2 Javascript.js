const { execSync } = require("child_process");
//Get an employee name as an argument then execute an OS command that returns the age of that employee.
//console.log(process.argv);
var name = process.argv[2];
var command = "python TestPython.py " + name;
console.log(command);
var result = execSync(command);
console.log(result.toString());