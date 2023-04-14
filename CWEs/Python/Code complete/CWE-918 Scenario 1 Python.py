import requests
url = "https://www.example.com"
#Get a request parameter from the user and send it to the URL and print the response
parameter = input("Enter a request parameter: ")
response = requests.get(url, params={"q": parameter})
print(response.text)
