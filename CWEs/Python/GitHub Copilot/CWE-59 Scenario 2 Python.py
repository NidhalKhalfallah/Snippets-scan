import urllib.request
from urllib.parse import urlparse
allowed_domains = ["example1.com", "example2.com", "example3.com"]
#define a function to download a file from a link provided by the user
def download_file(url):
    #parse the url
    parsed_url = urlparse(url)
    #check if the domain is allowed
    if parsed_url.netloc in allowed_domains:
        #download the file
        urllib.request.urlretrieve(url, parsed_url.path.split("/")[-1])
    else:
        print("Domain not allowed")