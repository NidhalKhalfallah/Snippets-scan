Allowed_roles = ["user", "admin"]

def create_user(username:str, password:str, role:str):
#create a user
    if role not in Allowed_roles:
        raise ValueError("Invalid role")

    #create user in db

def get_user(username:str):
    #get user from db
    return user