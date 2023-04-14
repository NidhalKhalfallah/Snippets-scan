#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <libxml/xmlschemas.h>

void send_xml_shoes_document(const char* xml_shoes_document, const char* recipient_url) {
    CURL *curl;
    CURLcode res;
    FILE *fd;
    CURLSH *sh;
    CURLSHcode sc;
    struct curl_slist *rcpt_list = NULL;
    struct curl_httppost *formpost = NULL;
    struct curl_httppost *lastptr = NULL;
    struct curl_slist *headerlist = NULL;
    const char *post_data = NULL;
    char *post_data_buffer = NULL;
    int post_data_size = 0;
    int i;
    int j;
    int k;
    int l;
    int m;
    int n;
    int o;
    int p;

    if ((curl = curl_easy_init()) == NULL) {
        fprintf(stderr, "curl_easy_init() failed\n");
        return;
    }
    if ((sh = curl_share_init()) == NULL) {
        fprintf(stderr, "curl_share_init() failed\n");
        return;
    }
    if ((fd = fopen(xml_shoes_document, "rb")) == NULL) {
        fprintf(stderr, "open %s failed\n", xml_shoes_document);
        return;
    }
    if ((rcpt_list = curl_slist_append(rcpt_list, "Content-Type: application/xml")) == NULL) {
        fprintf(stderr, "curl_slist_append() failed\n");
        return;
    }
    if ((headerlist = curl_slist_append(rcpt_list, "Accept: application/xml")) == NULL) {
        fprintf(stderr, "curl_slist_append() failed\n");
        return;
    }
    if ((formpost = curl_formadd(&sh, &fd, CURLFORM_COPYNAME, "recipient", CURLFORM_PTRNAME, recipient_url, CURLFORM_COPYCONTENTS, xml_shoes_document, CURLFORM_END)) == NULL) {
        fprintf(stderr, "curl_formadd() failed\n");
        return;
    }
    for (i = 0; i < post_data_size; i++) {
        if ((post_data_buffer = malloc(post_data_size + 1)) == NULL) {
            fprintf(stderr, "malloc() failed\n");
            return;
        }
        memset(post_data_buffer, 0, post_data_size + 1);
        memcpy(post_data_buffer, post_data + i, post_data_size);
        if ((post_data = malloc(post_data_size + 1)) == NULL) {
            fprintf(stderr, "malloc() failed\n");
            return;
        }
        memset(post_data, 0, post_data_size + 1);
        memcpy(post_data, post_data_buffer, post_data_size);
    }
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);
    curl_easy_setopt(curl, CURLOPT_URL, recipient_url);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_data);

    for (i = 0; i < post_data_size; i++) {
        free(post_data_buffer[i]);
    }
    free(post_data_buffer);
    curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);
    curl_easy_setopt(curl, CURLOPT_SHARE, sh);
    curl_easy_setopt(curl, CURLOPT_FORBID_REUSE, 1L);
    curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
    curl_easy_setopt(curl, CURLOPT_DNS_CACHE_TIMEOUT, 60L);
    curl_easy_setopt(curl, CURLOPT_DNS_USE_GLOBAL_CACHE, 1L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &post_data_size);
    curl_easy_setopt(curl, CURLOPT_READFUNCTION, read_callback);
    curl_easy_setopt(curl, CURLOPT_READDATA, &post_data_size);
    curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, header_callback);
    curl_easy_setopt(curl, CURLOPT_HEADERDATA, &post_data_size);
    curl_easy_setopt(curl, CURLOPT_WRITEHEADER, 1L);
    curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_data);

    rc = curl_easy_perform(curl);
    if (rc!= 0) {
        fprintf(stderr, "curl_easy_perform() failed\n");
        return;
    }
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
    if (response_code!= 200) {
        fprintf(stderr, "curl_easy_getinfo() failed\n");
        return;
    }
    curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &content_type);

    curl_easy_cleanup(curl);
    curl_global_cleanup();
    return;

    return;
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