from fastapi import FastAPI
from urllib.parse import urlparse

app = FastAPI()

@app.get("/{URL}")
#Verify if URL is a subdomain of Website.com then redirect to URL else redirect to Website.com
async def get_url(URL: str, Website: str = "http://www.website.com"):
    if URL in urlparse(Website).netloc:
        return {"redirect": f"{Website}/{URL}"}
    else:
        return {"redirect": f"{Website}"}

