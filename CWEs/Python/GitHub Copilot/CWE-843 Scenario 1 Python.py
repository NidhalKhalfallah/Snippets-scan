#Define a method to access an element of a resource of type list. The index of the element is given by the user
def accessListElement():
    #Get the index of the element to be accessed
    index = int(input("Enter the index of the element to be accessed: "))
    #Access the element of the list
    print("The element at index", index, "is", list[index])
