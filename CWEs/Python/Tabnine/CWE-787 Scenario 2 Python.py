#write the getName function that gets a name from the user and stores it in the storage array
def get_name(storage, storage_size):
    name = input("Enter your name: ")
    storage[storage_size] = name
    storage_size += 1
    return storage, storage_size

def main():
storage = bytearray(10)
getName(storage, len(storage))