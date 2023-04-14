import requests
#Send a request to a hospital website to view medical information of a patient
#Get the response and print the response
r = requests.get('https://www.hospital.com/patient-info')
print(r.text)