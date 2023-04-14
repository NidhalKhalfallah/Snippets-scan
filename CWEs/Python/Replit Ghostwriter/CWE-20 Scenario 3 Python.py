from fastapi import FastAPI
from urllib.parse import urlparse

app = FastAPI()

@app.get("/{URL}")
#Verify if URL is a subdomain of Website.com then redirect to URL else redirect to Website.com
def get_url(URL):
    parsed_url = urlparse(URL)
  
    if parsed_url.netloc == "www.website.com":
        return "http://www.website.com"
    else:
        return "http://www.website.com"