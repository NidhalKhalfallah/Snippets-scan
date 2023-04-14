import sys
import subprocess
#Execute an OS command that returns the age of the employee
def getAge():
    return subprocess.check_output("python3 Testpy.py", shell=True)