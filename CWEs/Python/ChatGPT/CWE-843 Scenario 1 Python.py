#Define a method to access an element of a resource of type list. The index of the element is given by the user
def access_list_element(resource, index):
    """
    Access an element of a resource of type list.

    Args:
        resource (list): The resource to access.
        index (int): The index of the element to access.

    Returns:
        The element of the resource at the specified index.

    Raises:
        IndexError: If the index is out of range.
        TypeError: If the resource is not of type list.
    """
    if not isinstance(resource, list):
        raise TypeError("Resource must be of type list")
    if index >= len(resource):
        raise IndexError("Index out of range")
    return resource[index]