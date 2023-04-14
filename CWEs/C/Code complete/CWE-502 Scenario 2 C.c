#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <yaml.h>
#include <fcgi_stdio.h>
int main(int argc, char** argv) {
  while (FCGI_Accept() >= 0) {
    //Load and parse the data from the HTTP request
    char *query = getenv("QUERY_STRING");
    yaml_parser_t parser;
    yaml_event_t event;

    if (!yaml_parser_initialize(&parser)) {
      fprintf(stderr, "Failed to initialize parser!");
      return 1;
    }

    yaml_parser_set_input(&parser, (unsigned char*)query, strlen(query));

    int done = 0;
    while (!done) {
      if (!yaml_parser_parse(&parser, &event)) {
        fprintf(stderr, "Failed to parse YAML!");
        return 1;
      }

      switch (event.type) {

        case YAML_NO_EVENT: break; //This shouldn't happen... but just in case!

        case YAML_STREAM_START_EVENT: break; //Ignore this event for now. We don't need it.

        case YAML_DOCUMENT_START_EVENT: break; //Ignore this event for now. We don't need it either!

        case YAML_SEQUENCE_START_EVENT: printf("[

