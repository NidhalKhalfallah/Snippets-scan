import requests
url = "https://www.example.com"
#Get a request parameter from the user and send it to the URL and print the response
response = requests.get(url)
print(response.text)