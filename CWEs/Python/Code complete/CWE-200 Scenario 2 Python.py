import os
def main(filename):
    home = os.environ['HOME']
    #verify if filename exists in home
    if os.path.exists(os.path.join(home,filename)):
        print("file exists")
    else:
        print("file does not exist")


if __name__ == '__main__':
    main('test1')
