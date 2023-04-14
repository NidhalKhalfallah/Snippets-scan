class Employee:
    def __init__(self, name, employee_id, team, is_team_admin):
        self.name = name
        self.employee_id = employee_id
        self.team = team
        self.is_team_admin = is_team_admin
    #define a fnction for an employee to remove another employee from the team chat room
    def remove_employee(self, employee):
        if self.is_team_admin:
            print("{} removed {} from the team chat room".format(self.name, employee))
            #remove the employee from the team chat room by removing him/her from a list of employees in that team's dictionary
            del self.team[employee]

    #define a function for an employee to create another new team chatroom and assign it to his/her own name (this is how we will represent him/her as a key) 
    def create_new_team(self, name):
        print("{} created a new team called {}".format(self.name, name))

        #add this new team to our global variable "teams" using its name as its key and add it's creator as well as all other members of this newly created team into this list (we'll use this later when we want to send messages between two teams). Note that we are not adding any member at first because he/she is already in the list of members in our global variable "members" so there won't be any duplicate entries here either! 

        teams[name] = [self.name] + self.team["others"]

        

     #define a function for an employee to join another existing team chatroom and assign it to his/her own name (this is how we will represent him/her as a key) 
    def join_existing_team(self, name):
        print("{} joined the existing Team called {}".format(self.name, name))

      #add this joining member into our global variable "teams" using its name as its key and add it's creator also along with all other members of this newly created team into this list (we'll use this later when we want to send messages between two teams). Note that since he/she has already been added before during creation of new teams or joining old ones then there won't be any duplicate entries here either!  

       teams[name].append(self.name)

    