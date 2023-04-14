#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <yaml.h>
#include <fcgi_stdio.h>
int main(int argc, char** argv) {
  while (FCGI_Accept() >= 0) {
    //Load and parse the data from the HTTP request
    char* data = getenv("CONTENT_LENGTH");
    int len = atoi(data);
    char* buffer = (char*)malloc(len);
    fread(buffer, 1, len, stdin);
    yaml_parser_t parser;
    yaml_token_t token;
    yaml_parser_initialize(&parser);
    yaml_parser_set_input_string(&parser, (unsigned char*)buffer, len);
    do {
      yaml_parser_scan(&parser, &token);
      switch (token.type) {
        case YAML_KEY_TOKEN:
          printf("Key: ");
          break;
        case YAML_VALUE_TOKEN:
          printf("Value: ");
          break;
        case YAML_SCALAR_TOKEN:
          printf("%s", token.data.scalar.value);
            break;
        default:
            break;
        }
        if (token.type != YAML_STREAM_END_TOKEN)
            yaml_token_delete(&token);
    } while (token.type != YAML_STREAM_END_TOKEN);
    yaml_token_delete(&token);
    yaml_parser_delete(&parser);
    free(buffer);
    }
    return 0;
}