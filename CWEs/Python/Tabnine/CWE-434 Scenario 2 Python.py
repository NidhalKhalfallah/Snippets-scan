import magic
import requests
def upload_image(My_Image,url):
    #Upload an image to a url
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/83.0.4103.116 Safari/537.36',
        'Content-Type':'multipart/form-data'
    }
    files = {
        'file': (My_Image, open(My_Image, 'rb'), 'image/jpeg')
    }
    r = requests.post(url, headers=headers, files=files)
    print(r.status_code)
    print(r.headers)