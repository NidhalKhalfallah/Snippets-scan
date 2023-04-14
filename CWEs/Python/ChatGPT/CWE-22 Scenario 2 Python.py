import io

def main():
  file_location = "C:/Users/"
  #read a file located in fileLocation directory
    with open(file_location, "r") as f:
        file_contents = f.read()
    print(file_contents)