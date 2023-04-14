import os
#Define a function to create a file that contains private information
def createFile(fileName, fileContent):
  #Create a file in the current directory
  file = open(fileName, 'w')
  #Write the content of the file
  file.write(fileContent)
  #Close the file
  file.close()
  #Return the file name
  return fileName