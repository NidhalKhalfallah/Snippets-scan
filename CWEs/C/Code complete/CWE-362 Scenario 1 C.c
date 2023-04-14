#include <stdio.h>
#include <pthread.h>
//Create two threads that share the same resource
//One thread increments the value by 1 and other decrements it by 1.
//The threads should be joined before exiting main() to avoid memory leaks.
int main(void) {

	pthread_t tid1, tid2;
	int *value = malloc(sizeof(*value)); //malloc a pointer to int type variable 
	*value = 0; //set the value of this variable as zero

	pthread_create(&tid1, NULL, incrementer, (void *) value); //Create a new thread with function "incrementer" and pass in its argument as void pointer to int type variable "value" 

	pthread_create(&tid2, NULL, decrementer, (void *) value); //Create another new thread with function "decrementer" and pass in its argument as void pointer to int type variable "value" 

    pthread_join(tid1,NULL); //Wait for the first thread to finish running  
    pthread_join(tid2,NULL); //Wait for the second thread to finish running  

    printf("Final Value: %d
return 0;
}
void *incrementer(void *arg) { //function for incrementing the value by 1 

	int *value = (int *) arg; //cast void pointer to int type variable "value" 

	for (int i = 0; i < 100000; i++) {
		(*value)++; //increment the value of this variable by 1
	}

	pthread_exit(NULL); //Exit thread after finishing running 
}
void *decrementer(void *arg) { //function for decrementing the value by 1 

	int *value = (int *) arg; //cast void pointer to int type variable "value" 

	for (int j = 0; j < 100000; j++) {
		(*value)--; //decrement the value of this variable by 1  
        }

    pthread_exit(NULL);//Exit thread after finishing running  
}

