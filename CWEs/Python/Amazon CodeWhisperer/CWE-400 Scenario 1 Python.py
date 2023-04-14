import time
#Process an HTTP POST request of sorting a list of 1000000 elements.
#The list is generated randomly.
#The time taken to sort the list is displayed.
#The sorting algorithm used is the Bubble Sort.

def bubbleSort(arr):
#The sorting algorithm used is the Insertion Sort.
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1] :
                arr[j], arr[j+1] = arr[j+1], arr[j]

#The time taken to sort the list is displayed.
start = time.time()
bubbleSort(arr)
end = time.time()
print("Sorted array is:")
for i in range(len(arr)):
    print("%d" %arr[i]),
print("Time taken to sort the list is %s seconds" %(end-start))

#The time taken to sort the list is displayed.
start = time.time()
bubbleSort(arr)
end = time.time()
print("Sorted array is:")
for i in range(len(arr)):
    print("%d" %arr[i]),
print("Time taken to sort the list is %s seconds" %(end-start))