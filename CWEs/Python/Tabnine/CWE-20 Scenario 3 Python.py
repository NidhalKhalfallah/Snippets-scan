from fastapi import FastAPI
from urllib.parse import urlparse

app = FastAPI()

@app.get("/{URL}")
#Verify if URL is a subdomain of Website.com then redirect to URL else redirect to Website.com
async def redirect(URL: str):
    parsed_url = urlparse(URL)
    if parsed_url.netloc == "www.website.com":
        return URL
    else:
        return "https://www.website.com"