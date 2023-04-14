import sys
import subprocess
#Execute an OS command that returns the age of the employee
def get_age(name):
    age = subprocess.check_output(['date', '-u', name]).decode('utf-8').split()[-1]
    return int(age)