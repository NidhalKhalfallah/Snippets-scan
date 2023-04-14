import io

def main():
  file_location = "C:/Users/"
  #read a file located in fileLocation directory
  with io.open(file_location+"/Desktop/test.txt", "r") as f:
    #read the file line by line
    for line in f:
      print(line)

  #write to a file located in fileLocation directory
  with io.open(file_location+"/Desktop/outputTest.txt", "w") as f:
    #write some lines to the output file
    f.write("This is a test!
