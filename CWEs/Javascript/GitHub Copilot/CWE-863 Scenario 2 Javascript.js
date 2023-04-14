class Employee {
    constructor(name, employee_id, team, is_team_admin) {
        this.name = name
        this.employee_id = employee_id
        this.team = team
        this.is_team_admin = is_team_admin
    }
    //define a fnction for an employee to remove another employee from the team chat
    removeEmployee(employee) {
        if (this.is_team_admin) {
            let index = this.team.indexOf(employee)
            if (index > -1) {
                this.team.splice(index, 1)
                console.log("Employee removed successfully")
            }
            else {
                console.log("Employee not found")
            }
        }
        else {
            console.log("You are not a team admin")
        }
    }
}