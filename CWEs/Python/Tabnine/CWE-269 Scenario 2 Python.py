Allowed_roles = ["user", "admin"]

def create_user(username:str, password:str, role:str):
#create a user

#check if user already exists
if User.query.filter_by(username=username).first() is not None:
    return "User already exists"


#check if role is valid
if role not in allowed_roles:
    return "Invalid role"

#create user
user = User(username=username, password=password, role=role)
db.session.add(user)
db.session.commit()

return "User created"