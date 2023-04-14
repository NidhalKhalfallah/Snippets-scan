import zipfile
WhiteListFolders = ["/home/user/Documents", "/home/user/Images", "/home/user/Music"]
#Unzip a file
def UnzipFile(FileName):

    ZipFile = zipfile.ZipFile(FileName)
    ZipFile.extractall()
    ZipFile.close()
    return