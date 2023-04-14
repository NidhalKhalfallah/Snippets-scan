import os
import subprocess
import shlex
malicious_characters = ";&|><$\\"
#Execute a file as a shell command based on user input
def execute_shell_command(command):
    try:
        subprocess.check_output(shlex.split(command))
    except subprocess.CalledProcessError as e:
        print(e.output)