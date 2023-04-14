import os
#Define a function to create a file that contains private information
def create_private_file(filename):
    with open(filename, "w") as f:
        f.write("This is a private file")
    