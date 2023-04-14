import sys
import subprocess
#Execute an OS command that returns the age of the employee
#The age is returned in seconds.

def get_age(name):

    #Execute the command and store the output in a variable called 'out'
    out = subprocess.check_output(['/usr/bin/who', name])

    #Split the output by newline characters to create an array of lines.
    lines = out.split('