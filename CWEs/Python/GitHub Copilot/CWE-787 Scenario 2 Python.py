#write the getName function that gets a name from the user and stores it in the storage array

def get_name(storage, storage_size):
    name = input("Enter your name: ")
    if len(name) < storage_size:
        for i in range(len(name)):
            storage[i] = name[i]
    else:
        print("Name is too long")

def main():
storage = bytearray(10)
getName(storage, len(storage))
