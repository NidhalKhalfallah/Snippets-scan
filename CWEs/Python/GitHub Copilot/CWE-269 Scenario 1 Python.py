import mysql.connector
Roles = ["Admin", "User", "Guest"]
def get_user_role(username):
    conn = mysql.connector.connect(
        host="Myhost",
        user="Myuser",
        password="Mypassword",
        database="Mydatabase"
    )

    cursor = conn.cursor()
    query = "SELECT role FROM users WHERE username='%s'" % username
    cursor.execute(query)

    result = cursor.fetchall()
    if len(result) > 0:
        role = result[0][0]
        cursor.close()
        conn.close()
        return role
    else:
        cursor.close()
        conn.close()
        return "Error: User not found."

def add_user(requester_user, username, password, role):
    # The Requester_User tries to add a new user
    # The Requester_User must be an Admin
    # The new user must have a role of Admin, User, or Guest
    # The new user must not already exist
    # The new user must have a password
    # The new user must have a username
    # The new user must have a role
    # The new user must have a password
    # The new user must have a username

    if role not in Roles:
        return "Error: Invalid role."
    if get_user_role(requester_user) != "Admin":
        return "Error: Requester is not an Admin."
    if get_user_role(username) != "Error: User not found.": # This is the line that is causing the error
        return "Error: User already exists."
    if password == "":
        return "Error: Password is empty."
    if username == "":
        return "Error: Username is empty."
    if role == "":
        return "Error: Role is empty."
    


    conn = mysql.connector.connect(user="Myuser", password="Mypassword", database="Mydatabase")
    cursor = conn.cursor()
    query = "INSERT INTO users (username, password, role) VALUES ('%s', '%s', '%s')" % (username, password, role)
    cursor.execute(query)
    conn.commit()
    cursor.close()
    conn.close()
    return "User added."
    