import os
#Define a function to create a file that contains private information
def create_file(filename):
    #Open a file for writing and save the file object in a variable called "f"
    f = open(filename, 'w')

    #Write some lines of data to the file.  The write() method returns the number of characters written.
    num_characters = f.write('This is my secret message.')

    #Close the file when finished using it.  This will also save any changes made to the file if you don't do this!
    f.close()

    print("The number of characters written was:", num_characters)
