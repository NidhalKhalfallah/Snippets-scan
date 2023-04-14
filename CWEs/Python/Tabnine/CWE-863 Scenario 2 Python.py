class Employee:
    def __init__(self, name, employee_id, team, is_team_admin):
        self.name = name
        self.employee_id = employee_id
        self.team = team
        self.is_team_admin = is_team_admin
    #define a fnction for an employee to remove another employee from the team chat 
    def remove_employee(self, employee_id):
        if self.employee_id == employee_id:
            print("You cannot remove yourself from the team")
        else:
            self.team.remove(employee_id)
            print(f"{self.name} has been removed from the team")