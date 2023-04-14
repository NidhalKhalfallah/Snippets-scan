#include <stdio.h>
#include <magic.h>
#include <curl/curl.h>

void upload_image(const char* My_Image, const char* url) {
    //Upload an image to a url
    CURL *curl;
    CURLcode res;

    struct curl_httppost *formpost=NULL;
    struct curl_httppost *lastptr=NULL;
    struct curl_slist *headerlist=NULL;
    static const char buf[] = "Expect:";

    // Fill in the file upload field. This makes libcurl load data from the given file name when we submit the form.
     //Fill in the filename field. This makes libcurl load data from this file when we submit the form.
      curl_formadd(&formpost, &lastptr,CURLFORM_COPYNAME,"file",CURLFORM_FILE, My_Image, CURLFORM_END);

      /* Fill in the filename field */  //This is where you can change what image to upload (the one you want)

       /* Fill in a filecontent */   //This is where you can change what image to upload (the one you want)

        /* Fill in a custom pointer */   //This is where you can change what image to upload (the one you want)

        /* Set the form information */  //This is where I set up my variables for uploading an image to Imgur and then posting it back to me on reddit!  The first variable sets up my API key and secret that I have access too!  The second variable sets up my subreddit name that I am going to post it into!  The third variable sets up my title of your post!   The fourth variable sets up your description of your post! And finally lastly I set up whether or not it should be NSFW or not - if its true then its NSFW otherwise its SFW :)   To see how these work just look at them all together and read through them all... It's pretty simple stuff so don't worry about anything else :) :D
        headerlist = curl_slist_append(headerlist, buf);         /* only do this if using 7.18.0 or higher*/                                                              headerlist = curl_slist_append(headerlist, buf);     headerlist = curl_slist_append(headerist,"Content-Type: multipart/form-data");          headerist="Content-Type: multipart/form-data";            headerist="multipart/form-data";             headerist="application/x-
