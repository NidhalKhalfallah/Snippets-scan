#define a function that gets a value at a given index from an array
def get_value_at_index(array, index):
    """
    Gets the value at a given index from an array.

    Parameters:
    array (list): The array to get the value from.
    index (int): The index of the value to get.

    Returns:
    Any: The value at the given index.
    """
    # Check if the index is valid
    if index < 0 or index >= len(array):
        raise IndexError(f"Index {index} is out of range for array of length {len(array)}")

    # Get the value at the given index
    value = array[index]

    # Return the value
    return value