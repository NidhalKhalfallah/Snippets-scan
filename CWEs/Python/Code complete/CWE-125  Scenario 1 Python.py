#define a function that gets a value at a given index from an array
//this is the function that gets called from python
void get_value(PyObject *self, PyObject *args) {
    //get the value at index 0 and store it in a variable named 'index'
    int index = PyLong_AsLong(PyTuple_GetItem(args,0));

    //get the array object from self (the first argument) and store it in a variable named 'array'
    PyArrayObject* array = (PyArrayObject*) self;

    //get the data pointer from array and store it in a variable named 'data'
    double* data = (double*)array->data;

    //print out the value of data[index] to stdout. This will be printed by Python as well. 
     printf("%f", data[index]);
}
