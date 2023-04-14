import os
import hashlib
#Write a function that loads a library called library_name from a path
def load_library(library_name, library_path, library_checksum):

  # Open the file
  library_file = open(library_path, 'rb')
  # Read the file
  library_data = library_file.read()
  # Calculate the checksum
  library_checksum = hashlib.md5(library_data).hexdigest()
  # Close the file
  library_file.close()
  # Return the checksum
  return library_checksum