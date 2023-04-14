#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <yaml.h>
#include <fcgi_stdio.h>
int main(int argc, char** argv) {
  while (FCGI_Accept() >= 0) {
    //Load and parse the data from the HTTP request
    yaml_parser_t parser;
    yaml_parser_initialize(&parser);
    yaml_parser_set_input_file(&parser, FCGI_GetParam("input", NULL));
    yaml_parser_load(&parser, &yaml_parser_scan_event);
    yaml_parser_delete(&parser);

    //Print the data to the HTTP response
    char* data = yaml_parser_steal_event(&yaml_parser_scan_event);
    if (data) {
      fprintf(stdout, "%s", data);
      free(data);
    }
  }
  return 0;
}