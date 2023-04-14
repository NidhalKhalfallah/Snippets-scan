import os.path
def read_file(filepath):
    base_path = '/Documents/MyProject'
    file_path = os.path.join(base_path, filepath)
    with open(file_path, 'r') as f:
        return f.read()