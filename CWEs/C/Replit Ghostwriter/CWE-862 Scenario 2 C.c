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
        response_str = "You bought a VIP merchandise";
        response = MHD_create_response_from_buffer(strlen(response_str),
                                                   (void *) response_str,
                                                     MHD_RESPMEM_MUST_COPY);
        ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
        MHD_destroy_response(response);
    } else if (strcmp(url, "/shop/sell/") == 0 && strcmp(method, "POST") == 0) {
        //sell a VIP merchandise
        response_str = "You sold a VIP merchandise";
        response = MHD_create_response_from_buffer(strlen(response_str),
          (void *) response_str, MHD_RESPMEM_MUST_COPY);
        ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
        MHD_destroy_response(response);
    } else {
        //return an error
        response_str = "You can't do that";
        response = MHD_create_response_from_buffer(strlen(response_str),
          (void *) response_str, MHD_RESPMEM_MUST_COPY);
        ret = MHD_queue_response(connection, MHD_HTTP_BAD_REQUEST, response);
        MHD_destroy_response(response);
    }
    return ret;
}