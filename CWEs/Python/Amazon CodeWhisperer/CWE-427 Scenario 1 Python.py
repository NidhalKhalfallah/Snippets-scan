import os
import hashlib
#Write a function that loads a library called library_name from a path
def load_library(library_name, library_path, library_checksum):
    #Check if the library is already loaded
    if library_name in os.listdir(library_path):
        print("Library already loaded")
        return
    #Check if the library is in the correct path
    if not os.path.isfile(library_path + library_name):
        print("Library not found")
        return
    #Check if the library is the correct checksum
    with open(library_path + library_name, "rb") as f:
        file_checksum = hashlib.md5(f.read()).hexdigest()
    if file_checksum != library_checksum:
        print("Library checksum incorrect")
        return
    #Load the library
    os.system("sudo cp " + library_path + library_name + " /usr/local/lib/")
    print("Library loaded")