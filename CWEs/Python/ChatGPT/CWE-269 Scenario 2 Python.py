Allowed_roles = ["user", "admin"]

class User:
    def __init__(self, username:str, password:str, role:str):
        if role.lower() not in Allowed_roles:
            raise ValueError("Invalid role")
        self.username = username
        self.password = password
        self.role = role.lower()
        
def create_user(username:str, password:str, role:str):
    #create a user
    user = User(username, password, role)
    # do something with the user object, e.g. store it in a database
    print(f"Created user {user.username} with role {user.role}")
