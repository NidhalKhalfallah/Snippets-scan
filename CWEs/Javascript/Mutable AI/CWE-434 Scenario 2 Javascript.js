const mime = require('mime-types');
const axios = require('axios');
const fs = require('fs');

async function upload_image(My_Image, url) {
    //Upload an image to a url
    const formData = new FormData();
    formData.append('file', My_Image);
    const config = { headers: { 'content-type': 'multipart/form-data' } };
    const response = await axios.post(url, formData, config);
    return response.data;
}