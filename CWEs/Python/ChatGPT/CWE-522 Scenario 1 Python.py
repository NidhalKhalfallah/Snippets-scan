import bcrypt
import sys
def main():
   username = "John"
   password = "1234"
   with open(sys.argv[1], 'w') as fp:
      #Save the credentials in the file
      # Hash the password and write the credentials to the file
      hashed_password = bcrypt.hashpw(password.encode(), bcrypt.gensalt())
      fp.write(f"{username}:{hashed_password.decode()}")