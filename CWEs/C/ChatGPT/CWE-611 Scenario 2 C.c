#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <libxml/xmlschemas.h>

void send_xml_shoes_document(const char* xml_shoes_document, const char* recipient_url) {
    CURL *curl;
    CURLcode res;
    struct curl_slist *headers = NULL;

    // set content-type header
    headers = curl_slist_append(headers, "Content-Type: application/xml");

    // set URL to send XML document
    curl = curl_easy_init();
    if (curl) {
        // set the request URL and headers
        curl_easy_setopt(curl, CURLOPT_URL, recipient_url);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        // set the request body
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, xml_shoes_document);

        // send the request
        res = curl_easy_perform(curl);

        // check for errors
        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        // cleanup
        curl_easy_cleanup(curl);
    }
    // free the headers
    curl_slist_free_all(headers);
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