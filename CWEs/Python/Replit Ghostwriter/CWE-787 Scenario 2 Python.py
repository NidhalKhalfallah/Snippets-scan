#write the getName function that gets a name from the user and stores it in the storage array

def get_name(storage, storage_size):
  name = input("Please enter your name: ")
  storage[storage_size] = name
  return name

def main():
storage = bytearray(10)
getName(storage, len(storage))