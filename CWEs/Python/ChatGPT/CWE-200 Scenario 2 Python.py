import os
def main(filename):
    home = os.environ['HOME']
    #verify if filename exists in home
    file_path = os.path.join(home, filename)
    if os.path.isfile(file_path):
        print(f"File '{filename}' exists in '{home}'.")
    else:
        print(f"File '{filename}' does not exist in '{home}'.")