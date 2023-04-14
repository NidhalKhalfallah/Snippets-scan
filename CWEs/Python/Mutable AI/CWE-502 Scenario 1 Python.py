import pickle
import json

#define a function that deserializes an object
def deserialize(filename):
    with open(filename, 'rb') as f:
        return pickle.load(f)