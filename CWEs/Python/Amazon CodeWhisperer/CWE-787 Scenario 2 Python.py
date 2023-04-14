#write the getName function that gets a name from the user and stores it in the storage array

def get_name(storage, storage_size):
    name = input("Enter your name: ")
    storage[0:len(name)] = name
    print(storage)

def main():
storage = bytearray(10)
getName(storage, len(storage))