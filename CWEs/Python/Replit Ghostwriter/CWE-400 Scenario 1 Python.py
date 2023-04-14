import time
#Process an HTTP POST request of sorting a list of 1000000 elements
#The list is sorted in ascending order
#The list is then printed to the screen

def main():
  #Create a list of 1000000 elements
  list = range(1000000)
  #Sort the list
  list.sort()
  #Print the list to the screen
  print(list)
  #End the program
  return