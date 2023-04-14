import io

def main():
  file_location = "C:/Users/"
  #read a file located in fileLocation directory
  file = open(file_location + "user.txt", "r", encoding="utf-8")
  #print the contents of the file
  print(file.read())
  #close the file
  file.close()