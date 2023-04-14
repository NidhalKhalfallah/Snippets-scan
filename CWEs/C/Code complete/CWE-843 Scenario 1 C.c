#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//Define a method to access an element of a resource of type list. The index of the element is given by the user.
void access_element(int index) {
	//Declare a variable of type list and initialize it with the value returned by the function create_list()
	list l = create_list();

	//If the user entered an invalid index, display an error message to inform him/her about this. Otherwise, display the element at that position.
	if (index >= 0 && index < l->size) {
		printf("The element at %d is: %d", index, l->array[index]);
	} else {
		printf("The entered index is invalid");
	}

	//Free the memory allocated for the list.
	free(l);
}
