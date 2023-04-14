//define a function that divides 2 dollars between x persons
#include <stdio.h>

void divide_money(int x) {
    if (x <= 0) {
        printf("Error: Number of persons must be greater than zero.\n");
        return;
    }

    float amount = 2.0 / x;
    printf("Each person gets $%.2f\n", amount);
}