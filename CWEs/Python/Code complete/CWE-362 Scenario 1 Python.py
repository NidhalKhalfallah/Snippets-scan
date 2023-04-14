import threading
#Create two threads that share the same resource
def thread_function(name):
    print("Thread %s: starting" % name)
    time.sleep(2)
    print("Thread %s: finishing" % name)


if __name__ == "__main__":

	thread1 = threading.Thread(target=thread_function, args=(1,))
	thread2 = threading.Thread(target=thread_function, args=(2,))

	print("Main : before Thread 1")  # prints Main : before Thread 1 first then after the second one is printed out in the same line because of the sleep function being called in both threads so they are executed at the same time and therefore on top of each other as well as printing out their output simultaneously

	#Start new Threads with different names (names are not important for this example but if you wanted to have a unique identifier for each thread you could use them here)  #prints Main : before Thread 1 first then after the second one is printed out in the same line because of the sleep function being called in both threads so they are executed at the same time and therefore on top of each other as well as printing out their output simultaneously

	thread1.start()   #this starts executing immediately since it's an independent process that runs independently from main without waiting for it to finish running - therefor no need to join it back together with wait() or join() which would make main wait until all threads have finished executing before moving forward - this is why we had to call start() instead of run(), otherwise main would block until all threads have finished executing and thus be stucked forever waiting for those threads to finish execution - calling start() allows us to execute our code concurrently while still keeping track of how many processes/threads we're currently using by incrementing a counter everytime we create a new process/thread object with .start(). This is useful if we want more than one concurrent process/processes running at once (e.g., multiple web crawlers). We can also use .join() if we want our program to keep going even though some processes might take longer than others (e.g., when downloading data from websites). The difference between these two methods is that .join() only waits until your current process finishes its execution whereas .start will let your current process continue on its own while allowing other processes to continue running concurrently while your current process continues on its own - this means that sometimes you'll see
