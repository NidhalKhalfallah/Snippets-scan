import os.path
def read_file(filepath):
    base_path = '/Documents/MyProject'
    filepath = os.path.join(base_path, filepath)

    with open(filepath, 'r') as f:
        lines = f.readlines()
        