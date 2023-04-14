#include <stdio.h>
//write a function that calculates the area of a rectangle
float calculate_rectangle_area(float length, float width) {
    if (length <= 0 || width <= 0) {
        printf("Error: Length and width must be greater than zero.\n");
        return -1;
    }

    float area = length * width;
    return area;
}