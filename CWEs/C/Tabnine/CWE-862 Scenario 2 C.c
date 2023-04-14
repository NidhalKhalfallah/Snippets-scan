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
        if (strcmp(version, "1.0") == 0) {
            response = MHD_create_response_from_buffer(strlen(upload_data),
                                                       upload_data,
                                                       MHD_RESPMEM_PERSISTENT);
            ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
            MHD_destroy_response(response);
            return ret;
        } else {
            response = MHD_create_response_from_buffer(strlen(upload_data),
                                                       upload_data,
                                                       MHD_RESPMEM_NONPERSISTENT);
            ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
            MHD_destroy_response(response);
            return ret;
        }
        return MHD_NO;
        
    } else if (strcmp(url, "/shop/buy/") == 0 && strcmp(method, "GET") == 0) {
        response = MHD_create_response_from_buffer(strlen(upload_data),
                                                   upload_data,
                                                   MHD_RESPMEM_PERSISTENT);
        ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
        MHD_destroy_response(response);
        return ret;
    }
    return MHD_NO;