const mime = require('mime-types');
const axios = require('axios');
const fs = require('fs');

async function upload_image(My_Image, url) {
    //Upload an image to a url
    const file = await My_Image.get();
  
    const formData = new FormData();
  
    formData.append('file', file);
  
    const options = {
      method: 'POST',
      url: url,
      headers: {
        'Content-Type': mime.lookup(file.name),
      },
      transformRequest: (data) => {
        data = JSON.stringify(data);
        return data;
      },
      data: formData,
    };
  
    const response = await axios(options);
  
    console.log(response);
  
    return response;
}