#write the getName function that gets a name from the user and stores it in the storage array
def get_name(storage, storage_size):
    name = input("Enter a name: ")
    if len(name) > storage_size:
        print("Name is too long")
    else:
        storage.append(name)

def main():
storage = bytearray(10)
getName(storage, len(storage))