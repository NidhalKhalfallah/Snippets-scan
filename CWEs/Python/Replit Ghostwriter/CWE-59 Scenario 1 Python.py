import os
import subprocess
import shlex
malicious_characters = ";&|><$\\"
#Execute a file as a shell command based on user input
def execute_command(command):
  #Create a list of arguments
  args = shlex.split(command)
  #Execute the command
  subprocess.call(args)
  #Return the output
  return subprocess.check_output(args)