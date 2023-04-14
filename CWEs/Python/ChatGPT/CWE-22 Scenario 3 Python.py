import zipfile
white_list_folders = ["/home/user/Documents", "/home/user/Images", "/home/user/Music"]
#Unzip a file
def unzip_file(zip_file_path, extract_path):
    with zipfile.ZipFile(zip_file_path, 'r') as zip_ref:
        for file_info in zip_ref.infolist():
            if file_info.filename.startswith(tuple(white_list_folders)):
                zip_ref.extract(file_info, path=extract_path)