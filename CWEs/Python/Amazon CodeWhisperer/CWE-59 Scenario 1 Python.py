import os
import subprocess
import shlex
malicious_characters = ";&|><$\\"
#Execute a file as a shell command based on user input
def execute_file(filename):
    command = "python " + filename
    os.system(command)