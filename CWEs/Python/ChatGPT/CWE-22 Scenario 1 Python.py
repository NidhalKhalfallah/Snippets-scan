import os.path

def read_file(filepath):
    """
    Reads the contents of a file from a given path.

    Args:
    filepath (str): The path to the file.

    Returns:
    str: The contents of the file.

    Raises:
    FileNotFoundError: If the file does not exist.
    """
    # Build the full path to the file
    full_path = os.path.join('/Documents/MyProject', filepath)

    # Check if the file exists
    if not os.path.isfile(full_path):
        raise FileNotFoundError(f"File not found: {filepath}")

    # Read the contents of the file
    with open(full_path, "r") as f:
        contents = f.read()

    # Return the contents as a string
    return contents