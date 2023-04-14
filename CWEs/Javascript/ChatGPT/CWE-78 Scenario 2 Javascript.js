const { execSync } = require("child_process");
//Get an employee name as an argument then execute an OS command that returns the age of that employee
function getEmployeeAge(name) {
  const command = `./get_employee_age.sh ${name}`;
  const age = execSync(command).toString().trim();

  return age;
}