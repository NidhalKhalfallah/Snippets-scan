#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <yaml.h>
#include <fcgi_stdio.h>
int main(int argc, char** argv) {
  while (FCGI_Accept() >= 0) {
    //Load and parse the data from the HTTP request
        char* content_length_str = getenv("CONTENT_LENGTH");
        if (content_length_str == NULL) {
            printf("Content-Length header is missing\n");
            continue;
        }

        long content_length = strtol(content_length_str, NULL, 10);
        char* request_body = (char*) malloc(content_length + 1);
        if (request_body == NULL) {
            printf("Failed to allocate memory for request body\n");
            continue;
        }

        fread(request_body, content_length, 1, stdin);
        request_body[content_length] = '\0';

        // Parse the request body as YAML
        yaml_parser_t parser;
        yaml_event_t event;
        yaml_parser_initialize(&parser);
        yaml_parser_set_input_string(&parser, (const unsigned char*) request_body, strlen(request_body));

        while (yaml_parser_parse(&parser, &event)) {
            // Process the event
            switch (event.type) {
                case YAML_SCALAR_EVENT:
                    printf("Scalar: %s\n", event.data.scalar.value);
                    break;
                case YAML_SEQUENCE_START_EVENT:
                    printf("Sequence start\n");
                    break;
                case YAML_SEQUENCE_END_EVENT:
                    printf("Sequence end\n");
                    break;
                case YAML_MAPPING_START_EVENT:
                    printf("Mapping start\n");
                    break;
                case YAML_MAPPING_END_EVENT:
                    printf("Mapping end\n");
                    break;
                default:
                    printf("Unknown event type\n");
            }

            yaml_event_delete(&event);
        }

        yaml_parser_delete(&parser);
        free(request_body);
    }

    return 0;
}