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
//TODO:
        response_str = "buy a VIP merchandise";
    } else if (strcmp(url, "/shop/get/") == 0 && strcmp(method, "POST") == 0) {
        //get the current purchase list of user
        //TODO:

    } else if (strcmp(url, "/shop/pay/") == 0 && strcmp(method, "POST") == 0) {
        //pay for the items in the shopping cart. The payment is done by a third-party service.

    } else if (strncmp(url, "/", 1) != 0) {
        return MHD_NO;  /* do not allow non-root URLs */
    }

    response = MHD_create_response_from_buffer (strlen (response_str), response_str, MHD_RESPMEM_PERSISTENT);

    ret = MHD_queue_response (connection, MHD_HTTP_OK, response);

    MHD_destroy_response (response);

    return ret;
}
