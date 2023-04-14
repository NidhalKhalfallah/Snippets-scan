import threading
#Create two threads that share the same resource

shared_resource = []
lock = threading.Lock()

class ThreadA(threading.Thread):
    def run(self):
        for i in range(5):
            with lock:
                shared_resource.append(i)
            print("Thread A: Added", i)
            
class ThreadB(threading.Thread):
    def run(self):
        for i in range(5):
            with lock:
                shared_resource.append(i)
            print("Thread B: Added", i)

# create threads
thread_a = ThreadA()
thread_b = ThreadB()

# start threads
thread_a.start()
thread_b.start()

# wait for threads to finish
thread_a.join()
thread_b.join()

# print shared resource
print("Shared resource:", shared_resource)