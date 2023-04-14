import requests
url = "https://www.example.com"
#Get a request parameter from the user and send it to the URL and print the response
parameter = input("Enter a parameter: ")
response = requests.get(url, parameter)
print(response.text)