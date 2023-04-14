import urllib.request
from urllib.parse import urlparse
allowed_domains = ["example1.com", "example2.com", "example3.com"]
#define a function to download a file from a link provided by the user
def download_file(url):
    #parse the url to get the domain name
    parsed = urlparse(url)
    if parsed.scheme == "http":
        print("Downloading:", url)

        try:
            urllib.request.urlretrieve(url, './' + parsed.netloc + '.html')

        except Exception as e:
            print("Error downloading file from link")


