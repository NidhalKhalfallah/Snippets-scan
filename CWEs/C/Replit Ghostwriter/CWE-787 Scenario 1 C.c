#include <stdio.h>
#include <stdlib.h>
int main() {
    float a[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    float b[3];

    //fill array b from array a
    for (int i = 0; i < 3; i++) {
        b[i] = a[i];
    }
  }