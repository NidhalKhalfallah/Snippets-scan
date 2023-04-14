Allowed_roles = ["user", "admin"]

def create_user(username:str, password:str, role:str):
#create a user
    if role not in Allowed_roles:
        raise ValueError(f"Invalid role {role}, please use one of {Allowed_roles}")
    print(f"Creating user {username}")
    print(f"Creating user {username}, with password {password} and role {role}")

create_user("XXXX", "1234", "user")