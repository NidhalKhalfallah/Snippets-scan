import bcrypt
import sys
def main():
   username = "John"
   password = "1234"
   with open(sys.argv[1], 'w') as fp:
      #Save the credentials in the file
      fp.write(username + '\n')
      fp.write(password)