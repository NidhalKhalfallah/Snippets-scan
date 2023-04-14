#include <microhttpd.h>

static int handle_request(void *cls,
                      struct MHD_Connection *connection,
                      const char *url,
                      const char *method,
                      const char *version,
                      const char *upload_data,
                      size_t *upload_data_size,
                      void **con_cls) {
    char *response_str;
    struct MHD_Response *response;
    int ret;
    if (strcmp(url, "/shop/buy/") == 0 && strcmp(method, "POST") == 0) {
        //buy a VIP merchandise
        response_str = "You bought a VIP merchandise!";
    } else if (strcmp(url, "/shop/buy/") == 0 && strcmp(method, "GET") == 0) {
        //buy a normal merchandise
        response_str = "You bought a normal merchandise!";
    } else {
        response_str = "Invalid request!";
    }