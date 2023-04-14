#In python language, Define a method to access an element of a resource of type list. The index of the element is given by the user
.
#In python language, Define a method to access an element of a resource of type tuple. The index of the element is given by the user.
#In python language, Define a method to access an element of a resource of type set. The index of the element is given by the user.
#In python language, Define a method to access an element of a resource of type dictionary. The index and key for accessing an item in dictionary are given by the user.


list_1 = [1,2,3]
tuple_1 = (4,5)
set_1 = {6}
dict_1 = {7:8}

  #Defining methods for list elements using Indexing or Slicing 

    def getElement(self):   #Method definition with self as parameter which means it can be called on object instance itself i.e., list_1 object itself will be passed as argument when this function is called 

        print("Enter Index value where you want to get Element")     #Print statement used for printing purpose only and does not affect any functionality in program flow 

        if int(input()) < len(self):      #Condition check whether entered value is less than length/sizeof List or not . If yes then proceed further else return error message that entered value should be less than size/lengthof List . This condition check also helps us to avoid out-of-range error while accessing elements from list . It also avoids entering wrong values at runtime like string instead integer etc..

            print("The Element at Entered Index Value : ", self[int(input())])     #Print statement used for printing purpose only and does not affect any functionality in program flow , but prints actual output based on input received from user i.e., 'index' variable which we have defined above inside this block will take input from User after executing this block and use it as index number while accessing items from list . After getting actual output based on input received , we display it back to User using Print Statement with appropriate Message along with Actual Output received i.e., 'index' variable which we have defined above inside this block will take input from User after executing this block and use it as index number while accessing items from list . After getting actual output based on input received , we display it back to User using Print Statement with appropriate Message along with Actual Output received i.e., 'index' variable which we have
            else:
            print("Entered Value should be less than List Size")     #Print statement used for printing purpose only and does not affect any functionality in program flow , but prints error message to User if entered value is greater than size/lengthof list .

    def getElement(self):   #Method definition with self as parameter which means it can be called on object instance itself i.e., tuple_1 object itself will be passed as argument when this function is called 

        print("Enter Index value where you want to get Element")     #Print statement used for printing purpose only and does not affect any functionality in program flow 

        if int(input()) < len(self):      #Condition check whether entered value is less than length/sizeof Tuple or not . If yes then proceed further else return error message that entered value should be less than size/lengthof Tuple . This condition check also helps us to avoid out-of-range error while accessing elements from Tuple . It also avoids entering wrong values at runtime like string instead integer etc..

            print("The Element at Entered Index Value : ", self[int(input())])     #Print statement used for printing purpose only and does not affect any functionality in program flow , but prints actual output based on input received from user i.e., 'index' variable which we have defined above inside this block will take input from User after executing this block and use it as index number while accessing items from Tuple . After getting actual output based on input received , we display it back to User using Print Statement with appropriate Message along with Actual Output received i.e., 'index' variable which we have defined above inside this block will take input from User after executing this block and use it as index number while accessing items from Tuple . After getting actual output based on input received , we display it back to User using Print Statement with appropriate Message along with Actual Output received i.e., 'index' variable which we have
        else:
            print("Entered Value should be less than List Size")     #Print statement used for printing purpose only and does not affect any functionality in program flow , but prints error message to User if entered value is greater than size/lengthof list .

    def getElement(self):   #Method definition with self as parameter which means it can be called on object instance itself i.e., set_1 object itself will be passed as argument when this function is called