import urllib.request
from urllib.parse import urlparse
allowed_domains = ["example1.com", "example2.com", "example3.com"]
#define a function to download a file from a link provided by the user
def download(url):
  # define a function to get the file name from the link
  def get_filename(url):
    parsed_url = urlparse(url)
    return parsed_url.path.split('/')[-1]
    
  # define a function to get the file size from the link
  def get_filesize(url):
    parsed_url = urlparse(url)
    return parsed_url.netloc + parsed_url.path
    
  # define a function to get the file url from the link
  def get_fileurl(url):
    parsed_url = urlparse(url)
    return parsed_url.scheme + '://' + parsed_url.netloc + parsed_url.path