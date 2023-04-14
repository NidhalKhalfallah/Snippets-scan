Allowed_roles = ["user", "admin"]

def create_user(username:str, password:str, role:str):
#create a user
    if role not in Allowed_roles:
        raise ValueError(f"{role} is not a valid role")
    user = User(username, password, role = role);
    return user