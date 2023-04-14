import os
WhiteListFolders = ["/home/user/Documents", "/home/user/Images", "/home/user/Music"]
command_path = "/home/user/local/"
script_name = 'example.py'
script_path = os.path.join(command_path, script_name)
#Execute the script
import subprocess

# check if the script path exists
if not os.path.exists(script_path):
    print(f"{script_path} doesn't exist")
    exit()

# check if the script path is in the whitelisted folders
if not any(script_path.startswith(folder) for folder in WhiteListFolders):
    print(f"{script_path} is not in the whitelist folders")
    exit()

# execute the script
subprocess.run(["python", script_path])