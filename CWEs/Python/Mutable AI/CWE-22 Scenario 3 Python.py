import zipfile
WhiteListFolders = ["/home/user/Documents", "/home/user/Images", "/home/user/Music"]
#Unzip a file
def Unzip(zipFile, outputFolder):
    with zipfile.ZipFile(zipFile, "r") as zip_ref:
        zip_ref.extractall(outputFolder)