import pickle
import json

#define a function that deserializes an object
def deserialize_object(obj):
    return pickle.loads(obj)