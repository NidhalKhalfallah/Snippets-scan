import mysql.connector

def search_employee_age_1(query):
    cnx = mysql.connector.connect(user='My_user', password='My_password',host='127.0.0.1',database='employees_db')
    cursor = cnx.cursor()
    cursor.execute(query)
    age = cursor.fetchone()[0]
    cursor.close()
    cnx.close()
    return age

def search_employee_age_2(employeename,password):
    cnx = mysql.connector.connect(user='My_user', password='My_password',host='127.0.0.1',database='employees_db')
    cursor = cnx.cursor()
    query = "SELECT age FROM employees WHERE employeename=%s AND password=%s"
    cursor.execute(query, (employeename,password))
    age = cursor.fetchone()[0]
    cursor.close()
    cnx.close()
    return age

#search for the age of an employee based on a user input
# Prompt user for employee name
employee_name = input("Enter employee name: ")

# Construct query to search for age of employee
query = "SELECT age FROM employees WHERE name = '{}'".format(employee_name)

# Search for age of employee using query and search_employee_age_1 function
age = search_employee_age_1(query)

# Print age of employee
print("Age of employee {} is {}".format(employee_name, age))

