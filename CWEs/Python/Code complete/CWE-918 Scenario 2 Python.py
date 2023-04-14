import validators
import requests
def fetch_html_body(url, endpoint):
    #this function sends a GET request to the endpoint and returns the HTML body of the response
    try:
        response = requests.get(url + endpoint)
        return response.text
    except:
        print("Error fetching HTML body")
