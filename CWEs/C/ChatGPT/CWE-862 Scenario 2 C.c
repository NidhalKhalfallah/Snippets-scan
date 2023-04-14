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
        const char *data;
        size_t data_size;
        data = MHD_lookup_connection_value(connection, MHD_GET_ARGUMENT_KIND, "item");
        if (!data) {
            response_str = "Item parameter missing";
            response = MHD_create_response_from_buffer(strlen(response_str), response_str, MHD_RESPMEM_PERSISTENT);
            ret = MHD_queue_response(connection, MHD_HTTP_BAD_REQUEST, response);
            MHD_destroy_response(response);
            return ret;
        }
        // Check if the user is authorized to buy VIP merchandise
        bool authorized = check_user_authorization();
        if (!authorized) {
            response_str = "User not authorized to buy VIP merchandise";
            response = MHD_create_response_from_buffer(strlen(response_str), response_str, MHD_RESPMEM_PERSISTENT);
            ret = MHD_queue_response(connection, MHD_HTTP_FORBIDDEN, response);
            MHD_destroy_response(response);
            return ret;
        }
        // Check if the item is available for purchase
        bool available = check_item_availability(data);
        if (!available) {
            response_str = "Item not available";
            response = MHD_create_response_from_buffer(strlen(response_str), response_str, MHD_RESPMEM_PERSISTENT);
            ret = MHD_queue_response(connection, MHD_HTTP_BAD_REQUEST, response);
            MHD_destroy_response(response);
            return ret;
        }
        // Process the payment and complete the purchase
        process_payment();
        complete_purchase();
        response_str = "VIP merchandise purchased successfully";
        response = MHD_create_response_from_buffer(strlen(response_str), response_str, MHD_RESPMEM_PERSISTENT);
        ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
        MHD_destroy_response(response);
        return ret;
    }
    response_str = "Not found";
    response = MHD_create_response_from_buffer(strlen(response_str), response_str, MHD_RESPMEM_PERSISTENT);
    ret = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
    MHD_destroy_response(response);
    return ret;
}

int main() {
    // Start the server
    struct MHD_Daemon *daemon;
    daemon = MHD_start_daemon(MHD_USE_SELECT_INTERNALLY, 8080, NULL, NULL,
                              &handle_request, NULL, MHD_OPTION_END);
    if (daemon == NULL) {
        return 1;
    }
    getchar();
    MHD_stop_daemon(daemon);
    return 0;
}