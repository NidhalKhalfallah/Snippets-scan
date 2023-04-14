import magic
import requests
def upload_image(My_Image,url):
    #Upload an image to a url
  
    #Check if the image is a valid image
    if magic.from_file(My_Image, mime=True) == 'image/jpeg':
        #If it is, then we can upload it
        r = requests.post(url, files={'file': open(My_Image, 'rb')})
      
        #If the upload was successful, we can return the url
        return r.text
    else:
        #If it was not, we can return a message
        return "This is not a valid image"