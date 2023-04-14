import threading
#Create two threads that share the same resource
def thread_function(name):
    print("Thread %s: starting" % name )
    thread_lock.acquire()
    print_time(name, 5)
    thread_lock.release()
    print("Thread %s: finishing" % name )
thread_lock = threading.Lock()
threads = []
#Create new threads
thread1 = threading.Thread(target=thread_function, args=(1,))
thread2 = threading.Thread(target=thread_function , args=(2,))
#Start new Threads
thread1.start()
thread2.start()
threads.append(thread1 )
threads.append(thread2 )
#Wait for all threads to complete
for thread in threads:
    thread.join()
print("Exiting Main Thread")