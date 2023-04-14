#include <stdio.h>
#include <unistd.h>
#include <time.h>
//Process an HTTP POST request of sorting a list of 1000000 elements
//in ascending order
int main(int argc, char **argv) {

	struct timespec start, end;
	double time_taken;

	if (clock_gettime(CLOCK_REALTIME, &start) == -1) { perror("clock gettime"); return 1; }

	//Read the list of 1000000 elements from stdin
	char *list = malloc(sizeof(char)*1000000); //Allocate memory for the array of integers to be sorted
	fgets(list, sizeof(list), stdin); //Read in a line of input from stdin and store it into list. 

}
