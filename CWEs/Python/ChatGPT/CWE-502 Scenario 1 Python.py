import pickle
import json

#define a function that deserializes an object

def deserialize_from_json(json_str):
    return json.loads(json_str)