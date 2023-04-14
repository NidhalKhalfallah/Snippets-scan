Allowed_roles = ["user", "admin"]

def create_user(username:str, password:str, role:str):
#create a user
if role not in Allowed_roles:
        raise ValueError("Invalid Role")

    user = User(username=username, password=password)
    user.role = role
    db.session.add(user)
    db.session.commit()
