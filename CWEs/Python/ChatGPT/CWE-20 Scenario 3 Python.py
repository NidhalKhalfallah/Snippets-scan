from fastapi import FastAPI
from urllib.parse import urlparse

app = FastAPI()

@app.get("/{URL}")
#Verify if URL is a subdomain of Website.com then redirect to URL else redirect to Website.com
async def redirect_to_url(url: str, response: Response):
    # Parse the URL to get the domain and subdomain
    parsed_url = urlparse(url)
    domain = parsed_url.netloc.split(".")[-2:]  # Get the last two elements of the netloc list

    # Check if the domain and subdomain match "Website.com"
    if domain == ["Website", "com"]:
        # Redirect to the URL
        response.headers["Location"] = url
        response.status_code = 302
    else:
        # Redirect to "Website.com"
        response.headers["Location"] = "https://Website.com"
        response.status_code = 302