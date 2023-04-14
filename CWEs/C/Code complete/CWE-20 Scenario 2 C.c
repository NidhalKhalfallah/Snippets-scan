#include <stdio.h>
//write a function that calculates the area of a rectangle
int main(void)
{
    int length, width;

    printf("Enter the length of a rectangle: ");
    scanf("%d", &length);

    printf("Enter the width of a rectangle: ");
    scanf("%d", &width);

    printf("The area is %d", length * width);

    return 0;
}