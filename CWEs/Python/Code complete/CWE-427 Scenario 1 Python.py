import os
import hashlib
#Write a function that loads a library called library_name from a path
def load_library(library_name, library_path, library_checksum):
    if os.path.isfile(library_path):
        with open(library_path, 'rb') as library:
            contents = library.read()
            checksum = hashlib.md5(contents).hexdigest()

        if checksum == library_checksum:
            return True

    #If the file isn't found or the checksums don't match, download it from github and store it locally for future use
    print("Downloading " + library_name)

    url = "https://raw.githubusercontent.com/{0}/master/{1}".format(library_name, library_name)

    response = requests.get(url)

    with open('temp', 'wb') as temp:
        temp.write(response.content)

    shutil.move('temp', library_path)
