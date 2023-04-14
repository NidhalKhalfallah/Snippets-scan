import validators
import requests
def fetch_html_body(url, endpoint):
    #this function sends a GET request to the endpoint and returns the HTML body of the response
  
    #validate the url
    if not validators.validate_url(url):
        return "Invalid URL"
      
    #validate the endpoint
    if not validators.validate_endpoint(endpoint):
        return "Invalid endpoint"
      
    #send the GET request
    response = requests.get(url)
  
    #if the request was successful
    if response.status_code == 200:
        #return the HTML body of the response
        return response.text
    else:
        #return the error message
        return "Invalid URL or endpoint"