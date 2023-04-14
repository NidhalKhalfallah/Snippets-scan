import validators
import requests
def fetch_html_body(url, endpoint):
    #this function sends a GET request to the endpoint and returns the HTML body of the response

    try:
        response = requests.get(url)
        if response.status_code == 200:
            return response.text
        else:
            return None
    except Exception as e:
        print(e)
        return None