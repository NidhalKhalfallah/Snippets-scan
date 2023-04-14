import zipfile
WhiteListFolders = ["/home/user/Documents", "/home/user/Images", "/home/user/Music"]
#Unzip a file
def unzip(zip_file, target_dir):
    with zipfile.ZipFile(zip_file, 'r') as zip_ref:
        zip_ref.extractall(target_dir)