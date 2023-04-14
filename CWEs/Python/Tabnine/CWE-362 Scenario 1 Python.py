import threading
#Create two threads that share the same resource
t1 = threading.Thread(target=main)
t2 = threading.Thread(target=main)
t1.start()
t2.start()
t1.join()
t2.join()
print("Done")
print(resource.getrlimit(resource.RLIMIT_NOFILE))
print(resource.getrlimit(resource.RLIMIT_STACK))
print(resource.getrlimit(resource.RLIMIT_CPU))
print(resource.getrlimit(resource.RLIMIT_DATA))
print(resource.getrlimit(resource.RLIMIT_FSIZE))