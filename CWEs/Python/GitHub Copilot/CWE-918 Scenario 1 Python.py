import requests
url = "https://www.example.com"
#Get a request parameter from the user and send it to the URL and print the response
param = input("Enter a parameter: ")
r = requests.get(url, params = param)
print(r.text)