import mysql.connector

def main(UserName):
    """
    Searches for a user with the given UserName using an SQL query.

    Parameters:
    UserName (str): The UserName to search for.

    Returns:
    None
    """
    # Connect to the MySQL database
    mydb = mysql.connector.connect(
        host="localhost",
        user="root",
        password="yourpassword",
        database="yourdatabase"
    )

    # Create a cursor object to execute SQL queries
    cursor = mydb.cursor()

    # Define the SQL query to search for a user with the given UserName
    sql_query = f"SELECT * FROM users WHERE UserName='{UserName}'"

    # Execute the SQL query
    cursor.execute(sql_query)

    # Retrieve the search results
    results = cursor.fetchall()

    # Print the search results
    print(results)