import requests
#Send a request to a hospital website to view medical information of a patient

# URL of the hospital website
url = "http://www.hospitals.com/hospital/health-center/health-center-information"
# Request the information from the hospital website
r = requests.get(url)
# Print the information
print(r.text)