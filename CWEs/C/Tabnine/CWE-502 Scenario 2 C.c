#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <yaml.h>
#include <fcgi_stdio.h>
int main(int argc, char** argv) {
  while (FCGI_Accept() >= 0) {
    //Load and parse the data from the HTTP request
    char* data = NULL;
    size_t length = 0;
    size_t offset = 0;
    size_t content_length = 0;
    size_t content_offset = 0;
    size_t content_length_parsed = 0;
    size_t content_offset_parsed = 0;
    size_t data_length = 0;
    size_t data_offset = 0;
    size_t data_length_parsed = 0;
    size_t data_offset_parsed = 0;
    size_t content_length_parsed = 0;
    size_t content_offset_parsed = 0;
    size_t data_length_parsed = 0;
    size_t data_offset_parsed = 0;
    size_t content_length_parsed = 0;
    size_t content_offset_parsed = 0;

    if (FCGI_FetchValues(data, &data_length, &data_offset, &data_length_parsed, &data_offset_parsed, &content_length, &content_offset, &content_length_parsed, &content_offset_parsed, &data_length_parsed, &data_offset_parsed, &content_length_parsed, &content_offset_parsed)!= FCGI_OK) {
      fprintf(stderr, "Failed to fetch values\n");
      return 1;
    }
    if (content_length_parsed!= content_length) {
      fprintf(stderr, "Failed to parse content length\n");
      return 1;
    }
    if (content_offset_parsed!= content_offset) {
      fprintf(stderr, "Failed to parse content offset\n");
      return 1;
    }
    if (data_length_parsed!= data_length) {
      fprintf(stderr, "Failed to parse data length\n");
      return 1;
    }
    if (data_offset_parsed!= data_offset) {
      fprintf(stderr, "Failed to parse data offset\n");
      return 1;
    }
    if (content_length_parsed!= content_length) {
      fprintf(stderr, "Failed to parse content length\n");
      return 1;
    }

    if (content_offset_parsed!= content_offset) {
      fprintf(stderr, "Failed to parse content offset\n");
      return 1;
    }
    