import threading
#Create two threads that share the same resource
t1 = threading.Thread(target=my_function, args=(1,))
t2 = threading.Thread(target=my_function, args=(2,))
#Start the threads
t1.start()
t2.start()
#Wait for the threads to finish
t1.join()
t2.join()
#Print the result
print("Result:", my_function(1))
print("Result:", my_function(2))