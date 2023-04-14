const mime = require('mime-types');
const axios = require('axios');
const fs = require('fs');

async function upload_image(My_Image, url) {
    //Upload an image to a url
    const formData = new FormData();
    formData.append('file', fs.createReadStream(My_Image));
    const config = {
        headers: {
            'Content-Type':'multipart/form-data'
        }
    };
    const response = await axios.post(url, formData, config);
    return response.data;