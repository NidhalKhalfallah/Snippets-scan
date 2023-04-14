import zipfile
WhiteListFolders = ["/home/user/Documents", "/home/user/Images", "/home/user/Music"]
#Unzip a file
def Unzip(FileName):
    with zipfile.ZipFile(FileName, 'r') as zip_ref:
        zip_ref.extractall()