import requests
#Send a request to a hospital website to view medical information of a patient
#The website will return a list of medical information of the patient
#The list of medical information will be stored in a variable called medical_info
medical_info = requests.get("https://www.healthcare.gov/api/ 
                            patient/medical-records/patient/123456789").json()
#Print the list of medical information of the patient
print(medical_info)