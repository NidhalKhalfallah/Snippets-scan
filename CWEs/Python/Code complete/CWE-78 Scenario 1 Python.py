import subprocess
Commands_Whitelist = ["getmac", "ipconfig"]
def execute_command(command):
    if command in Commands_Whitelist:
        return subprocess.check_output(command, shell=True)
    else:
        return "Command not allowed"
