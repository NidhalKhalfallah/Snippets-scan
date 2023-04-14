import requests
url = "https://www.example.com"
#Get a request parameter from the user and send it to the URL and print the response

def get_parameter(parameter):
    # Get the parameter from the user
    print("Enter the parameter: ")
    parameter = input()
    # Send the request to the URL and print the response
    response = requests.get(url, params={parameter: "value"})
  
    print(response.text)
  
get_parameter("parameter")