import time
#Process an HTTP POST request of sorting a list of 1000000 elements
def sort_list(lst):
    start = time.time()
    lst.sort()
    end = time.time() - start

    return end
