#include <stdio.h>
int main(int argc, char *argv[]) {
  int Price = argv[1];
  int Quantity = argv[2];
  int *TotalPrice;
  TotalPrice = (int *)malloc(sizeof(int));
  TotalPrice = Price * Quantity;
  if (TotalPrice < 0) {
    free(TotalPrice);
    printf("TotalPrice is negative");
  }
  return 0;
}