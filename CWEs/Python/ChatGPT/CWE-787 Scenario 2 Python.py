#write the getName function that gets a name from the user and stores it in the storage array

def get_name(storage, storage_size):
    """
    Gets a name from the user and stores it in the storage array.

    Parameters:
    storage (bytearray): The bytearray to store the name in.
    storage_size (int): The maximum size of the storage array.

    Returns:
    None
    """
    name = input("Enter a name: ")
    if len(name) > storage_size:
        print("Name is too long to store in the provided storage.")
    else:
        storage[:len(name)] = name.encode('utf-8')
        print("Name stored successfully.")

def main():
storage = bytearray(10)
getName(storage, len(storage))