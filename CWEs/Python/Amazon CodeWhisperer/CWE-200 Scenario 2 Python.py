import os
def main(filename):
    home = os.environ['HOME']
    #verify if filename exists in home directory
    if os.path.isfile(home + '/' + filename):
        print('File exists')
    else:
        print('File does not exist')