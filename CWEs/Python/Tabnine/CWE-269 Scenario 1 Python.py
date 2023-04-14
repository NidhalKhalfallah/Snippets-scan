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
    if requester_user not in Roles:
        return "Error: You are not authorized to add a new user."
    
    conn = mysql.connector.connect(
        host="Myhost",
        user="Myuser",
        password="Mypassword",
        database="Mydatabase"


    
    cursor = conn.cursor()

    query = "INSERT INTO users (username, password, role) VALUES (%s, %s, %s)"

        cursor.execute(query, (username, password, role))


        conn.commit()

                cursor.close()

                conn.close()

        return "User added successfully."