import subprocess
Commands_Whitelist = ["getmac", "ipconfig"]
def execute_command(command):
  try:
    subprocess.check_output(command, shell=True)
    return True
  except subprocess.CalledProcessError as e:
    return False