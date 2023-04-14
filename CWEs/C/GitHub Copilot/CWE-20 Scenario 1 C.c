//define a function that divides 2 dollars between x persons
//and returns the amount of money each person gets
//and the remainder
//the function should be called divide and should take 2 arguments
//the first argument is the amount of money to be divided
//the second argument is the number of people to divide the money between
//the function should return a structure of type money
//the structure should have 2 members
//the first member is the amount of money each person gets
//the second member is the remainder

#include <stdio.h>

struct money
{
    int dollars;
    int cents;
};

struct money divide(struct money amount, int number_of_people);

int main(void)
{
    struct money amount, result;
    int number_of_people;
    printf("Enter the amount of money to be divided: ");
    scanf("%d.%d", &amount.dollars, &amount.cents);
    printf("Enter the number of people to divide the money between: ");
    scanf("%d", &number_of_people);
    result = divide(amount, number_of_people);
    printf("Each person gets $%d.%d\n", result.dollars, result.cents);
    return 0;
}

struct money divide(struct money amount, int number_of_people)
{
    struct money result;
    result.dollars = amount.dollars / number_of_people;
    result.cents = amount.cents / number_of_people;
    return result;
}