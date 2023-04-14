import sys
import subprocess
#Get an employee name as an argument then execute an OS command that returns the age of that employee
#using the subprocess module.

#Get the name of the employee from the command line arguments.
employee = sys.argv[1]
#Execute the OS command that returns
age = subprocess.check_output(['wmic', 'useraccount', 'where name="' + employee + '"', 'get', 'age'])
#Print the age of the employee.
print(age)