import validators
import requests
def fetch_html_body(url, endpoint):
    #this function sends a GET request to the endpoint and returns the HTML body of the response
    if not validators.url(url):
        raise ValueError("Invalid URL")

    full_url = f"{url}/{endpoint}"
    response = requests.get(full_url)

    if response.status_code != 200:
        raise ValueError(f"Unexpected status code {response.status_code}")

    return response.text