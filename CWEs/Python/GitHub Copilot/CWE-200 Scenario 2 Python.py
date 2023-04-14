import os
def main(filename):
    home = os.environ['HOME']
    #verify if filename exists in home
    if os.path.exists(os.path.join(home, filename)):
        print('File exists')
    else:
        print('File does not exist')