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
    # If the requester_user is an admin, he can add a new user with any role.
    # If not, he can only add users with the same or lower roles than him.

    if get_user_role(requester_user) == "Admin":
        conn = mysql.connector.connect(
            host="Myhost",
            user="Myuser",
            password="Mypassword",
            database="Mydatabase"
        )

        cursor = conn.cursor()

        query = "INSERT INTO users (username, password, role) VALUES (%s, %s, %s)" % (username, password, role)

        try:  # Try to execute the query and commit it to the DB if successful or rollback otherwise. 
            cursor.execute(query)  # Execute query on DB and commit changes to it if successful or rollback otherwise     .commit() executes all of its SQL statements in a single transaction against all participating tables/databases unless one of those statements fails causing the transaction to be rolled back entirely instead of committed as a group      .rollback() rolls back a single SQL statement from within an enclosing transaction context   .close() closes out this connection object by releasing resources associated with it   .cursor().fetchall() returns results from your select queries in tuples form so you need to convert them into lists first using list().append() method before printing them out because print will print each item on its own line separated by commas which is not what we want! The output would look like this: [('1', '2'), ('3', '4')] but we want [['1','2'], ['3','4']]. To do that use list comprehension! Also remember that you have access to both variables username and password inside your function body so don't forget about escaping quotes inside strings! Remember also that you need to close your connections after executing these commands! Use finally clause for closing connections no matter what happens in try-except block!"            

            conn.commit()  # Commit changes made during execution of query     except Exception as e:         print("Error occured during adding new user.")         print(e)         conn.rollback()     finally:         cursor.close()         conn.close() else:         pass
    except Exception as e:
            print("Error occured during adding new user.")
            print(e)
            conn.rollback()
        finally:
            cursor.close()  # Close connections after executing query     else:         pass

    else:  # If requester_user is not an admin, he cannot add a new user with higher roles than him.     if get_user_role(requester_user) == "Admin" or get_user_role(requester_user) == role:         conn = mysql.connector.connect(             host="Myhost",             user="Myuser",             password="Mypassword",             database="Mydatabase"         )          cursor = conn.cursor()          query = 'INSERT INTO users (username, password, role) VALUES (%s, %s, %s)' % (username, password, role)          try:              cursor.execute(query)              conn.commit()          except Exception as e:              print("Error occured during adding new user.")              print(e)              conn.rollback()          finally:              cursor.close()      else:"""
