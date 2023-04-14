import pickle
import json

#define a function that deserializes an object
def deserialize(obj):
    return pickle.loads(pickle.dumps(obj))