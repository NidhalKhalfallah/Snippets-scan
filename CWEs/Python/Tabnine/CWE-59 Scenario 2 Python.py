import urllib.request
from urllib.parse import urlparse
allowed_domains = ["example1.com", "example2.com", "example3.com"]
#define a function to download a file from a link provided by the user
def download_file(url, filename):
    try:
        request = urllib.request.Request(url)
        request.add_header('User-Agent', 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/83.0.4103.116 Safari/537.36')
        response = urllib.request.urlopen(request)
        file = open(filename, 'wb')
        file.write(response.read())