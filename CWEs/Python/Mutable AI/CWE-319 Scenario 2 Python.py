import requests
def connect_to_url(url):
  res = requests.get(url, verify=False)
#Connect to an example URL
  return res.status_code
#Return the status code of the response
print(connect_to_url('https://www.google.com'))