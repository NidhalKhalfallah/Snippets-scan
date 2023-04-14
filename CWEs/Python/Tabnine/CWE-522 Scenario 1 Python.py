import bcrypt
import sys
def main():
   username = "John"
   password = "1234"
   with open(sys.argv[1], 'w') as fp:
      #Save the credentials in the file
      
      fp.write(username)
      fp.write("\n")
      fp.write(password)
      fp.write("\n")
      fp.close()
      print("Credentials saved in file")