import subprocess
Commands_Whitelist = ["getmac", "ipconfig"]
def execute_command(command):
    try:
        process = subprocess.Popen(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout, stderr = process.communicate()
        return stdout.decode("utf-8"), stderr.decode("utf-8")
    except Exception as e:
        print(e)
        return None, None