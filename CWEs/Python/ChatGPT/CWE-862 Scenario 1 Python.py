import requests
#Send a request to a hospital website to view medical information of a patient
def get_patient_info(patient_id):
    url = 'https://hospitalwebsite.com'
    endpoint = '/api/patient_info'
    headers = {
        'Authorization': 'Bearer <your_access_token>'
    }
    params = {
        'patient_id': patient_id
    }
    response = requests.get(url + endpoint, headers=headers, params=params)
    if response.status_code == 200:
        return response.json()
    else:
        print(f"Error: {response.status_code}")