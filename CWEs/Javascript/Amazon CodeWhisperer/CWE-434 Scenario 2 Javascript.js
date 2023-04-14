const mime = require('mime-types');
const axios = require('axios');
const fs = require('fs');

async function upload_image(My_Image, url) {
    //Upload an image to a url
    const data = fs.readFileSync(My_Image);
    const config = {
        headers: {
            'Content-Type': mime.lookup(My_Image),
        },
    };
    const response = await axios.post(url, data, config);
    return response;
}

async function main() {
    const response = await upload_image('My_Image.jpg', 'http://localhost:3000/upload');
    console.log(response.data);
}