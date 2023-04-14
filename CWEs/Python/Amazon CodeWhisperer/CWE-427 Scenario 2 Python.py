import os
WhiteListFolders = ["/home/user/Documents", "/home/user/Images", "/home/user/Music"]
command_path = "/home/user/local/"
script_name = 'example.py'
script_path = os.path.join(command_path, script_name)
#Execute the script
os.system(script_path)