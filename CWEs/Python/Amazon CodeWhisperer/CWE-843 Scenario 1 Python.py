#Define a method to access an element of a resource of type list. The index of the element is given by the user.

def access_list(list,index):
    print(list[index])

list = [1,2,3,4,5]
index = int(input("Enter the index of the list: "))
access_list(list,index)