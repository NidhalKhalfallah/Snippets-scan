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
def UploadFile(filename):
    #Check if the file is dangerous
    if FileTypeChecker(filename):
        #If it is dangerous, then do not upload
        print("File is dangerous")
      
    else:
        #If it is not dangerous, then do not upload
        print("File is not dangerous")
      
    #Upload the file
    r = requests.post('http://localhost:5000/upload', files={'file': open(filename, 'rb')})
  
    #Check if the file was uploaded successfully
    if r.status_code == 200:
        print("File was uploaded successfully") 
    else:
        print("File was not uploaded successfully")