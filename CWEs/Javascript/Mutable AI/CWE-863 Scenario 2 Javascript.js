class Employee {
   constructor(name, employee_id, team, is_team_admin) {
       this.name = name
       this.employee_id = employee_id
       this.team = team
       this.is_team_admin = is_team_admin
   }
   //define a fnction for an employee to remove another employee from the team chat
   remove_employee(employee_id) {
       //remove the employee from the team chat
       this.team.remove_employee(employee_id)
       //remove the employee from the employee list of the team chat
       this.team.employees.splice(this.team.employees.indexOf(employee_id), 1)
   }
}