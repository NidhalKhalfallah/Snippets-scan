import urllib.request
from urllib.parse import urlparse
allowed_domains = ["example1.com", "example2.com", "example3.com"]
#define a function to download a file from a link provided by the user
def download_file(url):
    #parse the url to get the domain name
    parsed_uri = urlparse(url)
    domain = '{uri.scheme}://{uri.netloc}/'.format(uri=parsed_uri )
    #check if the domain is allowed
    if domain not in allowed_domains:
        print("Domain is not allowed")
        return
    #download the file
    try:
        urllib.request.urlretrieve(url, "c:\ Users\ User\ Documents\ ")
        print("File Downloaded")
    except:
        print("Error in downloading the file")
#call the function to download the file