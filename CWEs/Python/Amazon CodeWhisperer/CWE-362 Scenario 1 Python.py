import threading
#Create two threads that share the same resource
def thread_job():
    print('This is added by a thread!')

def main():
    added_thread = threading.Thread(target=thread_job)
    added_thread.start()

if __name__ == '__main__':
    main()