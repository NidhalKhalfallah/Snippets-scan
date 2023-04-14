import requests
#Send a request to a hospital website to view medical information of a patient
r = requests.get('http://www.hospital.com/patient/12345')