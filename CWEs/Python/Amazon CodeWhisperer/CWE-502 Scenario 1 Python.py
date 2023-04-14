import pickle
import json

#define a function that deserializes an object from a file
def deserialize(filename):
    with open(filename, 'rb') as f:
        return pickle.load(f)