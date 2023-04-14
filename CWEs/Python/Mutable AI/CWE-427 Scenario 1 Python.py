import os
import hashlib
#Write a function that loads a library called library_name from a path
def load_library(library_name, library_path, library_checksum):
    #Check if the library is already loaded
    if library_name in sys.modules:
        return sys.modules[library_name]
        #Check if the library is already loaded in the current directory
        if os.path.exists(library_path):
            #Check if the library is already loaded in the current directory with the same checksum
            if os.path.exists(library_path) and os.path.exists and os.path.exists(library_path):
                return sys.modules[library_name]
            #Load the library from the current directory if the checksum is different from the one in the current directory        
            else:
                #Load the library from the current directory        
                return load_library_from_path(library_name, library_path)
                #Load the library from the current directory
                
