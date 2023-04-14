import os
import subprocess
import shlex
malicious_characters = ";&|><$\\"
#Execute a file as a shell command based on user input
def execute_file(file_name):
    #Check if the file exists and is a file
    if os.path.isfile(file_name) and os.path.isfile(file_name):
        #Check if the file is a python file
        if file_name.endswith(".py"):
            #Execute the file as a python script with the python interpreter
            subprocess.call(["python", file_name])
        #Check if the file is a shell script based on the file extension
        elif file_name.endswith(".sh"):
            #Execute the file as a shell script with the bash interpreter 
            subprocess.call(["bash", file_name])
        #Check if the file is a batch file based on the file extension 
        elif file_name.endswith(".bat"):
            #Execute the file as a batch file with the cmd interpreter 
            subprocess.call(["cmd", file_name])
        #Check if the file is a perl script based on the file extension 
        elif file_name.endswith(".pl"): 
            #Execute the file as a perl script with the perl interpreter 
            subprocess.call(["perl", file_name]) 
        #Check if the file is a ruby script based on the file extension 
        elif file_name.endswith(".rb"): 
            #Execute the file as a ruby script with the ruby interpreter 
            subprocess. call(["ruby", file_name]) 
        #Check if the file is a python script based on the file extension 
        elif file_name.endswith(".py"): 
            #Execute the file as a python script with the python interpreter 