#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <libxml/xmlschemas.h>

void send_xml_shoes_document(const char* xml_shoes_document, const char* recipient_url) {
  CURL *curl;
  CURLcode res;
  struct curl_slist *headers = NULL;

  curl = curl_easy_init();
  if (curl) {
    headers = curl_slist_append(headers, "Content-Type: application/xml");
    headers = curl_slist_append(headers, "Accept: application/xml");
    headers = curl_slist_append(headers, "User-Agent: curl/7.18.0");
    headers = curl_slist_append(headers, "Accept-Encoding: gzip, deflate");
    headers = curl_slist_append(headers, "Connection: keep-alive");
    headers = curl_slist_append(headers, "Host: ");
    headers = curl_slist_append(headers, recipient_url);
    headers = curl_slist_append(headers, "Content-Length: ");
    headers = curl_slist_append(headers, "Content-Type: application/xml");
    headers = curl_slist_append(headers, "Expect: 100-continue");

    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_URL, recipient_url);
    curl_easy_setopt(curl, CURLOPT_POST, 1);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, xml_shoes_document);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
    curl_easy_setopt(curl, CURLOPT_HEADER, 1);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYSTATUS, 0);

    res = curl_easy_perform(curl);
    if (res!= CURLE_OK) {
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
        curl_easy_strerror(res));
    }
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