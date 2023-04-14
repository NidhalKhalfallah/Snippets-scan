import requests
import magic

def upload_image(image_path: str, url: str):
    # Open the image file
    with open(image_path, "rb") as image_file:
        # Determine the file type using magic
        mime_type = magic.from_file(image_path, mime=True)
        # Set the headers for the POST request
        headers = {
            "Content-Type": mime_type,
            "Content-Length": str(os.path.getsize(image_path))
        }
        # Make the POST request to the URL
        response = requests.post(url, headers=headers, data=image_file)
        # Print the response status code and text
        print(response.status_code, response.text)