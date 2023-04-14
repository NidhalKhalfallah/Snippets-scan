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
#Write a function that uploads a file
def upload_file(filename):
    url = 'http://127.0.0.1:5000/upload'
    files = {'file': open(filename, 'rb')}
    r = requests.post(url, files=files)
    print(r.text)