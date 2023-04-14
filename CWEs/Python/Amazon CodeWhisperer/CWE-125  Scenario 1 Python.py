#define a function that gets a value at a given index from an array
def get_value_at_index(array, index):
    if index < 0:
        return "Invalid index"
    else:
        return array[index]