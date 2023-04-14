import os
import subprocess
import shlex
malicious_characters = ";&|><$\\"
#Execute a file as a shell command based on user input
def execute_file(filename):
    if filename.endswith(".py"):
        command = "python3 %s" % (filename)
    elif filename.endswith(".sh"):
        command = "./%s" % (filename)

    args = shlex.split(command)

    proc = subprocess.Popen(args, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)

    while True:
        output = proc.stdout.readline()[:-1] #remove newline character
        if output == '' and proc.poll() != None:
            break

        print(output)

    rc = proc.poll()
    return rc