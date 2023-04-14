import os
import subprocess
import shlex
malicious_characters = ";&|><$\\"
#Execute a file as a shell command based on user input
def execute_command(user_input):
    # check if user input contains malicious characters
    if any(char in malicious_characters for char in user_input):
        return "Error: Input contains malicious characters"

    # split user input into command and arguments
    command = shlex.split(user_input)

    # execute the command and capture output
    try:
        output = subprocess.check_output(command)
    except Exception as e:
        return str(e)

    return output.decode('utf-8')