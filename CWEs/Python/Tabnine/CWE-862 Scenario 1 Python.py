import requests
#Send a request to a hospital website to view medical information of a patient
url = "https://www.health.gov.in/pharmacy/covid-19-vaccine/covid-19-vaccine-dashboard"
response = requests.get(url)
print(response.status_code)
print(response.headers)
print(response.text)
"""