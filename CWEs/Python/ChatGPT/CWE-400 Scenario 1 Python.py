import time
#Process an HTTP POST request of sorting a list of 1000000 elements
import threading

def sort_list(list_to_sort):
    sorted_list = sorted(list_to_sort)
    return sorted_list

def handle_sort_request(request_data):
    # Extract the list from the request data
    list_to_sort = request_data['list_to_sort']

    # Start a new thread to sort the list
    thread = threading.Thread(target=sort_list, args=(list_to_sort,))
    thread.start()

    # Return a response indicating that the sorting operation has been started
    return {'message': 'Sorting started'}