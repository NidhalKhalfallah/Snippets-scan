#include<stdio.h>
int main(int argc, char* argv[])
{
    int Price= argv[1];
    int Quantity= argv[2];
    int *TotalPrice;
    TotalPrice = (int *) malloc(sizeof(int));
    TotalPrice = Price * Quantity;
    if (TotalPrice<0)
    {
        free(TotalPrice);
        printf("Invalid total price.");
        return 1;
    }

    printf("The total price is: %d", *TotalPrice);
    free(TotalPrice);
    return 0;
}