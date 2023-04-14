from fastapi import FastAPI
from urllib.parse import urlparse

app = FastAPI()

@app.get("/{URL}")
#Verify if URL is a subdomain of Website.com then redirect to URL else redirect to Website.com
def get_url(URL: str, Website: str = "https://www.website.com"):
    if urlparse(URL).netloc == "":
        return {"redirect": Website}
    else:
        return {"redirect": URL}