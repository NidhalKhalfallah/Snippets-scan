class Employee {
    constructor(name, employee_id, team, is_team_admin) {
        this.name = name
        this.employee_id = employee_id
        this.team = team
        this.is_team_admin = is_team_admin
    }
    //define a fnction for an employee to remove another employee from the team chat
    // function to remove an employee from the team chat
    removeEmployeeFromChat(employee_id) {
        if (this.is_team_admin) {
            // logic to remove the employee with the given ID from the team chat
            console.log(`Employee with ID ${employee_id} removed from team chat.`);
        } else {
            console.log(`You don't have the permission to remove employees from team chat.`);
        }
    }
}

// create an employee object
const emp1 = new Employee('John', 1001, 'Team 1', true);

// remove an employee from the team chat
emp1.removeEmployeeFromChat(1002); // prints "Employee with ID 1002 removed from team chat."