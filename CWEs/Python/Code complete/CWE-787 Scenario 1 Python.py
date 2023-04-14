from numpy import ndarray

a = ndarray(shape=(5,), dtype=float)
b = ndarray(shape=(3,), dtype=float)
a[0] = 1.0
a[1] = 2.0
a[2] = 3.0
a[3] = 4.0
a[4] = 5.0
#fill array b from array a
b[0] = a[0]
b[1] = a[1]

b[2] = a[2]
