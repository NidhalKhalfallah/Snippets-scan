import os
import hashlib
#Write a function that loads a library called library_name from a path
def load_library(library_name, library_path, library_checksum):
    #Check if the library is already loaded
    if library_name in sys.modules:
        return sys.modules[library_name]
    #Load the library
    library = imp.load_source(library_name, library_path)
    #Check if the library is already loaded
    if library_name in sys.modules:
        return sys.modules[library_name]