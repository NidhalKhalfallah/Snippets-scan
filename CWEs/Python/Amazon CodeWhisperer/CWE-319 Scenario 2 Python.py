import requests
def connect_to_url(url):
  res = requests.get(url, verify=False)
#Connect to an example URL
  return res.text
#Return the text of the response object

if __name__ == "__main__":
  url = "https://www.example.com"
  print(connect_to_url(url))