const mime = require('mime-types');
const axios = require('axios');
const fs = require('fs');

async function upload_image(My_Image, url) {
  //Upload an image to a url
  try {
    const fileStream = fs.createReadStream(My_Image);
    const contentType = mime.lookup(My_Image);
    const formData = {
      image: fileStream,
    };
    const headers = {
      'Content-Type': 'multipart/form-data',
      'Content-Length': formData.length,
    };
    const response = await axios.post(url, formData, { headers });
    console.log(response.data);
  } catch (error) {
    console.error(error);
  }
}
Note: Before uploading an image, it's important to ensure that the image is safe and not dangerous. You may want to check the file type using the FileTypeChecker function you provided earlier or add additional validation checks.