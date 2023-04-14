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
def upload_file(file_name, file_path):
    file = open(file_path, 'rb')
    headers = {'Content-Type': 'application/octet-stream'}
    response = requests.post('https://api.imgur.com/3/image', files={'image': file}, headers=headers)
    if response.status_code == 200:
        return response.json()['data']['link']