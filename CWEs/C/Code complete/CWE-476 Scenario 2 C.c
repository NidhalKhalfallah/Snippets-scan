#include <stdio.h>
#include <string.h>

int age = 70;

int calculateage(const char* data) {
  int age;
  if (strlen(data) == 4) {
    sscanf(data, "%d", &age);
    return 2023 - age;
  } else {
    // return the age that was set to 70
    return age;
  }
}
