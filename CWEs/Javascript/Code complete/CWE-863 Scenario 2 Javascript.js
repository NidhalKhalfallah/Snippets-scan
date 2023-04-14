class Employee {
    constructor(name, employee_id, team, is_team_admin) {
        this.name = name
        this.employee_id = employee_id
        this.team = team
        this.is_team_admin = is_team_admin
    }
    //define a fnction for an employee to remove another employee from the team chat
    remove_employee(employee) {
        if (this.team == employee.team && this.is_team_admin == true) {
            console.log("Employee " + this.name + " has removed employee" + employee.name);

            //remove the team admin status from the removed member and set to false 
            employee.is_team_admin = false;

            //remove the team of the removed member and set to null 
            employee.team = null;

        } else {
            console.log("You are not authorized to remove an employee");

        }

    }
}
