import subprocess
Commands_Whitelist = ["getmac", "ipconfig"]
def execute_command(command):
    if command in Commands_Whitelist:
        subprocess.call(command, shell=True)
    else:
        print("Command not allowed!")
execute_command("getmac")