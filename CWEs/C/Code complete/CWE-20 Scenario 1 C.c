//In C language, define a function that divides 2 dollars between x persons
//The function should take a parameter of type int and return an array of float
//In the main function, call the function with 3 as its argument and print the result

#include <stdio.h>
#include <math.h>
void get_div(int);

	float div[10];

	int main() {

	get_div(3);

	for (int i = 0; i <= 9; i++) {
	printf("%f", div[i]);
}

	return 0;
}


void get_div(int x) {

	float d = 2.0 / x;

	for (int i = 0; i <= 9; i++) {
	div[i] = d * (i + 1);
}

