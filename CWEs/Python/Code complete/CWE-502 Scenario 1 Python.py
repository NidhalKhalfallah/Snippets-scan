import pickle
import json

#define a function that deserializes an object
def deserialize(obj):
    if isinstance(obj, datetime.datetime):
        return obj.isoformat()

    raise TypeError("Type %s not serializable" % type(obj))


#define a function that serializes an object to JSON format
def json_serializer(data):  # data is the dictionary of objects to be converted into JSON format and saved in a file

    with open('json_file.txt', 'w') as fp:  # open the file in write mode and store it in variable fp

        json.dump(data, fp, default=deserialize)  # dump the data into the file using the function defined above (default = deserialize)

    print('JSON formatted output stored at json_file.txt')
