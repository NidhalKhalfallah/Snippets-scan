import os
import hashlib
#Write a function that loads a library called library_name from a path
def load_library(library_name, library_path, library_checksum):
    # Check if library exists
    if not os.path.exists(library_path):
        raise ImportError(f"{library_name} not found at {library_path}")

    # Check the checksum of the library
    with open(library_path, "rb") as f:
        checksum = hashlib.sha256(f.read()).hexdigest()
        if checksum != library_checksum:
            raise ImportError(f"{library_name} checksum mismatch")

    # Load the library
    try:
        lib = ctypes.CDLL(library_path)
    except OSError as e:
        raise ImportError(f"Failed to load {library_name}: {e}")

    return lib