import requests
def connect_to_url(url):
  res = requests.get(url, verify=False)
  return res
#Connect to an example URL
connect_to_url("https://www.google.com/")


