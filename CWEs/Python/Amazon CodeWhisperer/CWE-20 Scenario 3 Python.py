from fastapi import FastAPI
from urllib.parse import urlparse

app = FastAPI()

@app.get("/{URL}")
#Verify if URL is a subdomain of Website.com then redirect to URL else redirect to Website.com
def verify(URL: str):
    url = urlparse(URL)
    if url.netloc == "www.website.com":
        return {"URL": "www.website.com"}
    else:
        return {"URL": "www.website.com"}