import validators
import requests
def fetch_html_body(url, endpoint):
    #this function sends a GET request to the endpoint and returns the HTML body of the response
    try:
        response = requests.get(url + endpoint)
        return response.text
    except:
        return """<h1>Error in fetching HTML body</h1>"""
def check_url(url):
    #this function checks if the url is valid or not
    return validators.url(url)
def check_endpoint(endpoint):
    #this function checks if the endpoint is valid or not
    return endpoint.startswith('/')
def check_response(response):
    #this function checks if the response is valid or not
    return response.startswith('<')
    #this function checks if the response is valid or not
    return response.status_code == 200
def check_html_body(html_body):
    #this function checks if the HTML body is valid or not
    return html_body.startswith('<')
def check_html_body(html_body):
    #this function checks if the HTML body is valid or not
    return html_body.startswith('<')
def main():
    #this function is the main function
    url = input("Enter the URL: ")
    endpoint = input("Enter the endpoint: ")
    if check_url(url) and check_endpoint(endpoint):
        html_body = fetch_html_body(url, endpoint)
        if check_response(html_body):
            print("The HTML body is valid")
        else:
            print("The HTML body is invalid")
    else:
        print("The URL or the endpoint is invalid")