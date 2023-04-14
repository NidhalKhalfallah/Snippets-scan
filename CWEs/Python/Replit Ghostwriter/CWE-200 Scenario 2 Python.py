import os
def main(filename):
    home = os.environ['HOME']
    #verify if filename exists in home
    if not os.path.isfile(home + filename):
        print("File not found")