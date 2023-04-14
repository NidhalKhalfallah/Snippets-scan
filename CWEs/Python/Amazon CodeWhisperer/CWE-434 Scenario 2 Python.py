import magic
import requests
def upload_image(My_Image,url):
    #Upload an image to a url
    #My_Image is the image file name
    #url is the url to upload to
    #returns the response from the server
    with open(My_Image, 'rb') as f:
        file_data = f.read()
        files = {'file': (My_Image, file_data)}
        r = requests.post(url, files=files)
        return r.text