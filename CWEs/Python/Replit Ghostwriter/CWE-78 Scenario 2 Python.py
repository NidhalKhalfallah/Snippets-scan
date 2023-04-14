import sys
import subprocess
#Execute an OS command that returns the age of the employee

def main():
  #Get the employee name
  employee = input("Enter the employee name: ")
  #Get the age of the employee
  age = subprocess.check_output(["age", employee])
  #Print the age
  print(age)
  #Exit the program
  sys.exit()