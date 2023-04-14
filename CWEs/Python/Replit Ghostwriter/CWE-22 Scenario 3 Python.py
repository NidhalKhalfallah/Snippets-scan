import zipfile
WhiteListFolders = ["/home/user/Documents", "/home/user/Images", "/home/user/Music"]
#Unzip a file
def unzip(zipFile, folder):
  with zipfile.ZipFile(zipFile, "r") as zf:
    for name in zf.namelist():
      if name.startswith(folder):
        print(name)
        zf.extract(name, path=folder)