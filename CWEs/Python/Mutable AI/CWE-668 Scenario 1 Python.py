import os
#Define a function to create a file that contains private information
def create_file(filename):
    #Create the file and write the information to it.
    with open(filename, 'w') as file_object:
        file_object.write("This is a test file.\n")
        file_object.write("This is the second line.\n")