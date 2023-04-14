import magic
import requests
def upload_image(My_Image,url):
    #Upload an image to a url
    files = {'file': open(My_Image, 'rb')}
    r = requests.post(url, files=files)
    return r.text