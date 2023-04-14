import os
import subprocess
import shlex
malicious_characters = ";&|><$\\"
#Execute a file as a shell command based on user input
def execute_file():
    file = input("Enter the file to execute: ")
    #Check for malicious characters
    for char in malicious_characters:
        if char in file:
            print("Malicious character detected. Exiting.")
            return
    #Execute the file
    os.system(file)