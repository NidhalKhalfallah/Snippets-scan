import os
import hashlib
#Write a function that loads a library called library_name from a path
def load_library(library_name, library_path, library_checksum):
    #Check if the library exists
    if os.path.exists(library_path):
        #Check if the checksum of the library is correct
        if hashlib.md5(open(library_path, 'rb').read()).hexdigest() == library_checksum:
            #Load the library
            library = __import__(library_name)
            #Return the library
            return library
        else:
            #Return an error
            return "Error: Checksum of the library is not correct"
    else:
        #Return an error
        return "Error: Library does not exist"