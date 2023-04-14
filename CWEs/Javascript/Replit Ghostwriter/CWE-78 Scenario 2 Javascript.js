const { execSync } = require("child_process");
//Get an employee name as an argument then execute an OS command that returns the age of that employee

const args = process.argv.slice(2);
const name = args[0];
const cmd = args[1];
execSync(cmd, { stdio: "inherit" });
console.log(cmd);
console.log(execSync(cmd, { stdio: "inherit" }));