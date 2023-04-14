import requests
url = "https://www.example.com"
#Get a request parameter from the user and send it to the URL and print the response
param_name = input("Enter request parameter name: ")
param_value = input("Enter request parameter value: ")

response = requests.get(url, params={param_name: param_value})

print(response.content)