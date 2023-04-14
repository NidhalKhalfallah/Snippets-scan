from fastapi import FastAPI
from urllib.parse import urlparse

app = FastAPI()

@app.get("/{URL}")
#Verify if URL is a subdomain of Website.com then redirect to URL else redirect to Website.com
def read_item(URL: str):
    if urlparse(URL).netloc == "Website.com":
        return {"URL": URL}
    else:
        return {"URL": "Website.com"}