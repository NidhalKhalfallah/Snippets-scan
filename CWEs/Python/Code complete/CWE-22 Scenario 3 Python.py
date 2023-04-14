import zipfile
WhiteListFolders = ["/home/user/Documents", "/home/user/Images", "/home/user/Music"]
#Unzip a file
def Unzip(file):
    try:
        zip_ref = zipfile.ZipFile(file, 'r')
        zip_ref.extractall("/home/user")
        print("[+] File extracted successfully.")
        #zip_ref.close()

    except Exception as e:  # If an error occurs the program will print it out and exit the function with a return value of 0 (false) so that we can continue to the next file in our loop. This is done to prevent errors from stopping all execution of our script if one or more files fail to extract properly.

        print ("[-] Error extracting file " + str(e))  # Prints out what went wrong and exits the function with a return value of 0 (false). We can then continue to process other files in our loop without having any issues occur due to one failing extraction attempt.

        return False

    else:  # If no error occurred during extraction it will execute this code block and return True so that we can move on to the next file in our loop without having any issues occur from an unsuccessful extraction attempt for another file in our list.

         print ("[+] File Extracted Successfully.")  # Prints a success message stating that we were able to extract the requested file successfully and returns true so that we can move on to processing other files without having any issues from an unsuccessful extraction attempt for another file in our list.

         return True
