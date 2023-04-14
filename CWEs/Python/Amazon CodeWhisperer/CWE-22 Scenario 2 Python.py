import io

def main():
  file_location = "C:/Users/"
  #read a file located in fileLocation directory
  with open(file_location + "test.txt", 'r') as f:
    #read the file
    content = f.read()
    #print the file
    print(content)