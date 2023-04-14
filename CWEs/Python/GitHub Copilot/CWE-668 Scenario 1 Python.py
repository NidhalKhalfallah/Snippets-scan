import os
#Define a function to create a file that contains private information
def create_file():
    #Create a file
    f = open("private.txt", "w")
    #Write private information to the file
    f.write("This is a private file")
    #Close the file
    f.close()