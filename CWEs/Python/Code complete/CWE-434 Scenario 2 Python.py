import magic
import requests
def upload_image(My_Image,url):
    #Upload an image to a url
    My_Image = Image.open(image)
    My_Image = My_Image.convert('RGB')
    imgByteArr = io.BytesIO()
    My_Image.save(imgByteArr, format='JPEG')
    imgByteArr=imgByteArr.getvalue()

    files={'file': ('image', imgByteArr)}

    r=requests.post(url,files=files)