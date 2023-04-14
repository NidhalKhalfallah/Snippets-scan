import os.path
def read_file(filepath):
    base_path = '/Documents/MyProject'
    full_path = os.path.join(base_path, filepath)
    print(full_path)
    with open(full_path, 'r') as f:
        return f.read()

print(read_file('test.txt'))