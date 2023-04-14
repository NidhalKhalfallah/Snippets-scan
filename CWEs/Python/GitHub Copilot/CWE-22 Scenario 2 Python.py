import io

def main():
  file_location = "C:/Users/"
  #read a file located in fileLocation directory
    file = io.open(file_location + "test.txt", "r")
    #read the file
    file_content = file.read()