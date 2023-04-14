#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <libxml/xmlschemas.h>

void send_xml_shoes_document(const char* xml_shoes_document, const char* recipient_url) {
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();

    if (curl) {
        struct curl_slist* headers = NULL; 
        headers = curl_slist_append(headers, "Content-Type: text/xml");

        char url[100];
        sprintf(url,"%s", recipient_url);

        // Send the request to the server and get a response back.  In this case, we are sending an HTTP POST command with a body containing the XML document.  
        res = curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers); // set http header for post method.  Without this line of code, it will be treated as GET method.  
	res |= curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, strlen(xmlshoesdocument)); // Set size of data being sent in bytes.  
	res |= curl_easy_setopt(curl, CURLOPT_POSTFIELDS, xmlshoesdocument); // Set data to send in HTTP POST request body.  	    	    	    	        

       /* Perform the request */ 
       res = curl->perform();

       /* Check for errors */ 
       if (res != 0) { fprintf("Error sending shoes document"); }

       /* always cleanup */ 
       curl_easy_cleanup(curl);
    }
}
    

int main(int argc, char **argv) {
    char *shoes_xsd = "<xs:schema xmlns:xs='http://www.w3.org/2001/XMLSchema'>"
                      "  <xs:element name='shoes'>"
                      "    <xs:complexType>"
                      "      <xs:sequence>"
                      "        <xs:element name='type' type='xs:string'/>"
                      "        <xs:element name='model' type='xs:string'/>"
                      "        <xs:element name='size' type='xs:positiveInteger'/>"
                      "      </xs:sequence>"
                      "    </xs:complexType>"
                      "  </xs:element>"
                      "</xs:schema>";
    xmlSchemaParserCtxtPtr parser_ctxt = xmlSchemaNewMemParserCtxt(shoes_xsd, strlen(shoes_xsd));
    xmlSchemaPtr schema = xmlSchemaParse(parser_ctxt);
    xmlSchemaFreeParserCtxt(parser_ctxt);
    xmlDocPtr doc = xmlReadFile("shoes.xml", NULL, 0);
    send_xml_document(doc,schema,"http://example.com/receive_xml");
    return 0;
}