Allowed_roles = ["user", "admin"]

def create_user(username:str, password:str, role:str):
#create a user
  if role == "user":
    user = User(username, password)
    db.session.add(user)
    db.session.commit()
    return user
  elif role == "admin":
    admin = Admin(username, password)
    db.session.add(admin)
    db.session.commit()
    return admin
  else:
    return None