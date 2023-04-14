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
    # The Requester_User tries to add a new user.
    # The requester_user should be an Admin.
    # The username and password should be valid.
    # The role should be one of the three roles.
    # If the user is successfully added, return True.
    # If the user cannot be added, return False.
    if requester_user != "Admin":
        return False
    if role not in Roles:
        return False
    conn = mysql.connector.connect(
        host="Myhost",
        user="XXXXXX",
        password="XXXXXX",
        database="Mydatabase"
    )

    cursor = conn.cursor()
    query = "INSERT INTO users (username, password, role) VALUES ('%s', '%s', '%s')" % (username, password, role)
    cursor.execute(query)
    conn.commit()
    cursor.close()
    conn.close()
    return True