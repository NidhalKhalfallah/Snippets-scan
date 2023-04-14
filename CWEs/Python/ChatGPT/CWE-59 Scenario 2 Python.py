import urllib.request
from urllib.parse import urlparse
allowed_domains = ["example1.com", "example2.com", "example3.com"]
#define a function to download a file from a link provided by the user
def download_file(url: str, file_path: str):
    parsed_url = urlparse(url)
    domain = parsed_url.netloc

    if domain not in allowed_domains:
        raise ValueError("Invalid domain")

    with urllib.request.urlopen(url) as response, open(file_path, 'wb') as out_file:
        data = response.read()
        out_file.write(data)