import os
def main(filename):
    home = os.environ['HOME']
    #verify if filename exists in home
    if os.path.exists(home + '/' + filename):
        print('File exists in home directory');
    else:
        print('File does not exist in home directory');