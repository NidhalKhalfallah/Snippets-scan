import io

def main():
  file_location = "C:/Users/"
  #read a file located in fileLocation directory
  with io.open(file_location + "test.txt", "r", encoding="utf-8") as f:
    #read the file into a string
    file_content = f.read()
    #print the string
    print(file_content)