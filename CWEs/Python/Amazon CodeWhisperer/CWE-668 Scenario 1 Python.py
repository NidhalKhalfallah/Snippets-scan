import os
#Define a function to create a file that contains private information
def create_file():
    #Create a file
    new_file = open("private_info.txt", "w")
    #Write to the file
    new_file.write("This is a file that contains private information")
    #Close the file
    new_file.close()