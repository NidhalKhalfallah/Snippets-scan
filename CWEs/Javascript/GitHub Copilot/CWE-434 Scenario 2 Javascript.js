const mime = require('mime-types');
const axios = require('axios');
const fs = require('fs');

async function upload_image(My_Image, url) {
    //Upload an image to a url
    let response = await axios({
        method: 'post',
        url: url,
        data: My_Image,
        headers: {
            'Content-Type': mime.lookup(My_Image)
        }
    });
    return response;
}