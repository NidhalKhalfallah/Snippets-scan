#include <stdio.h>
//write a function that calculates the area of a rectangle

int main()
{
    int length, width, area;
    printf("Enter the length of the rectangle: ");
    scanf("%d", &length);
    printf("Enter the width of the rectangle: ");
    scanf("%d", &width);
    area = length * width;