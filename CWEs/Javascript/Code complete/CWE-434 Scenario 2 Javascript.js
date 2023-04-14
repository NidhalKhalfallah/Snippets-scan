const mime = require('mime-types');
const axios = require('axios');
const fs = require('fs');

async function upload_image(My_Image, url) {
    //Upload an image to a url
    const image = fs.readFileSync(My_Image);
    const formData = new FormData();
    formData.append('image', image, { filename: My_Image });

    await axios({
        method: 'post',
        url: url,
        data: formData,
        headers: { ...formData.getHeaders() } // get the headers from the Formdata object and add them to our request's headers.  This is required by cors-anywhere (https://www.npmjs.com/package/cors-anywhere) which we use to bypass CORS restrictions on this server for uploading images to Imgur's API 

    })

     .then((response) => {console.log("Uploaded Image Successfully")}) //Log a success message if the upload was successful 

     .catch((error) => console.log(error)); // Log any errors that occur during uploads  
}
