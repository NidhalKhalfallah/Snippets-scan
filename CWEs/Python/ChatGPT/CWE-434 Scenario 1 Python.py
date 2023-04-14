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
def upload_file(file_path, url):
    # Check file type
    file_name = os.path.basename(file_path)
    if FileTypeChecker(file_name):
        raise ValueError("File type not allowed")

    # Upload file
    with open(file_path, 'rb') as file:
        files = {'file': (file_name, file)}
        response = requests.post(url, files=files)
        response.raise_for_status()

    print("File uploaded successfully")