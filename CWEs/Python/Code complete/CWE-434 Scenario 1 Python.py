import os
import requests
def FileTypeChecker(filename):
    base, ext = os.path.splitext(filename)
    is_dangerous = True
    non_dangerous_extensions = ['txt', 'doc', 'ppt', 'odt']
    for i in range(4):
        if ext == non_dangerous_extensions[i]:
            is_dangerous = False
    return is_dangerous
#Write a function that uploads a file to a given URL.
#The file should be uploaded as a multi-part POST request.
#If the file is not found or cannot be read, return an error message.
def UploadFile(url, filename):
    if os.path.isfile(filename) and FileTypeChecker(filename) == False:
        with open(filename, 'rb') as f:
            r = requests.post(url, files={'file': (os.path.basename(filename), f)})

        print("Status code:" + str(r))

    else:
        print('File does not exist or is dangerous!')
