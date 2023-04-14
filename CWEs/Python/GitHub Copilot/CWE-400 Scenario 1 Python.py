import time
#Process an HTTP POST request of sorting a list of 1000000 elements
def application(environ, start_response):
    start_response('200 OK', [('Content-Type', 'text/html')])
    #Sort a list of 1000000 elements
    list = []
    for i in range(1000000):
        list.append(i)
    list.sort()
    return [b"Hello World!"]